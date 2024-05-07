#include "Quaternion.h"
#include <cmath>
#include <sstream>

namespace dragonbreath
{
    const Quaternion Quaternion::identity(1.0, 0.0, 0.0, 0.0);
    // ------------------------------------------------------------------------
    const Quaternion Quaternion::zero(0.0, 0.0, 0.0, 0.0);
    // ------------------------------------------------------------------------
    Quaternion Quaternion::fromEulerAngles(const Vector3& eulerAngles)
    {
        // Extract the roll, pitch, and yaw values from eulerAngles
        float roll = eulerAngles.getX();
        float pitch = eulerAngles.getY();
        float yaw = eulerAngles.getZ();

        // Simply call fromRollPitchYaw to take care of the rest...
        return fromRollPitchYaw(roll, pitch, yaw);
    }
    // ------------------------------------------------------------------------
    Quaternion Quaternion::fromRollPitchYaw(float roll, float pitch, float yaw)
    {
        // Calculate abbreviations for angular functions
        float cosRoll = std::cos(roll * 0.5);
        float cosPitch = std::cos(pitch * 0.5);
        float cosYaw = std::cos(yaw * 0.5);
        float sinRoll = std::sin(roll * 0.5);
        float sinPitch = std::sin(pitch * 0.5);
        float sinYaw = std::sin(yaw * 0.5);
        
        // Calculate repeated, intermediate values for efficiency
        float cosPitchCosYaw = cosPitch * cosYaw;
        float sinPitchSinYaw = sinPitch * sinYaw;
        float cosPitchSinYaw = cosPitch * sinYaw;
        float sinPitchCosYaw = sinPitch * cosYaw;
    
        // Make quaternion w, x, y, z components
        float w = cosRoll * cosPitchCosYaw + sinRoll * sinPitchSinYaw;
        float x = sinRoll * cosPitchCosYaw - cosRoll * sinPitchSinYaw;
        float y = cosRoll * sinPitchCosYaw + sinRoll * cosPitchSinYaw;
        float z = cosRoll * cosPitchSinYaw - sinRoll * sinPitchCosYaw;

        // Return new quaternion
        return Quaternion(w, x, y, z);
    }
    // ------------------------------------------------------------------------
    Vector3 Quaternion::toEulerAngles() const
    {
        // TODO Normalize the quaternion components first!

        // Calculate roll, pitch, and yaw
        float roll = std::atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y));
        float pitch = std::asin(2 * (w * y - x * z));
        float yaw = std::atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z));

        // Return euler angles
        return Vector3(roll, pitch, yaw);
    }
    // ------------------------------------------------------------------------
    void Quaternion::set(float _w, float _x, float _y, float _z)
    {
        w = _w;
        x = _x;
        y = _y;
        z = _z;
    }
    // ------------------------------------------------------------------------
    std::string Quaternion::toString() const
    {
        std::ostringstream oss;
        oss << w << "," << x << "," << y << "," << z;
        return oss.str();
    }
} // namespace dragonbreath

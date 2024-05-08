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
    void Quaternion::normalize()
    {
        // Find the length of the quaternion
        float magnitude = std::sqrt(w * w + x * x + y * y + z * z);

        // Divide the quaternion by the magnitude of the quaternion
        w /= magnitude;
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }
    // ------------------------------------------------------------------------
    Quaternion Quaternion::toNormalized() const
    {
        // Find the length of the quaternion
        float magnitude = std::sqrt(w * w + x * x + y * y + z * z);

        // Return quaternion by value
        return Quaternion(
            w / magnitude,
            x / magnitude,
            y / magnitude,
            z / magnitude);
    }
    // ------------------------------------------------------------------------
    Vector3 Quaternion::toEulerAngles() const
    {
        // Normalize the quaternion components first to avoid math errors
        Quaternion normQ = this->toNormalized(); 

        // Calculate roll, pitch, and yaw
        float roll = std::atan2(
            2 * (normQ.w * normQ.x + normQ.y * normQ.z),
            1 - 2 * (normQ.x * normQ.x + normQ.y * normQ.y));
        float pitch = std::asin(2 * (normQ.w * normQ.y - normQ.x * normQ.z));
        float yaw = std::atan2(
            2 * (normQ.w * normQ.z + normQ.x * normQ.y),
            1 - 2 * (normQ.y * normQ.y + normQ.z * normQ.z));

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

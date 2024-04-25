#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"

namespace dragonbreath
{
    /**
    
    */
    class Quaternion
    {
    public:
        /**

        */
        Quaternion();

        /**

        */
        Quaternion(float _x, float _y, float _z, float _w);
    private:
        /**

        */
        Vector3 eulerAngles {};

        /**

        */
        float x {};

        /**

        */
        float y {};

        /**

        */
        float z {};

        /**

        */
        float w {};
    }; // class Quaternion
} // namespace dragonbreath

#endif

#ifndef QUATERNION_H
#define QUATERNION_H

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

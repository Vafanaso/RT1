// #ifndef RAYTRACER_HPP
// #define RAYTRACER_HPP

// #include <vector>

// struct Vec3f {
//   float x, y, z;
//   Vec3f(float xx = 0, float yy = 0, float zz = 0) : x(xx), y(yy), z(zz) {}
//   Vec3f operator+(const Vec3f &v) const;
//   Vec3f operator-(const Vec3f &v) const;
//   Vec3f operator*(float f) const;
//   Vec3f normalize();
// };

// struct Sphere {
//   Vec3f center;
//   float radius;
//   Vec3f surfaceColor, emissionColor;
//   float transparency, reflection;

//   Sphere(const Vec3f &c, float r, const Vec3f &sc, float refl = 0,
//          float transp = 0, const Vec3f &ec = Vec3f());
//   bool intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0,
//                  float &t1) const;
// };

// // Declare render and scene functions
// void render(const std::vector<Sphere> &spheres, unsigned char *pixels,
//             int width, int height);
// std::vector<Sphere> create_scene();

// #endif

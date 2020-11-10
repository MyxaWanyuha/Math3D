//#include <iostream>
//#include "Math.h"
//
//int main2()
//{
//	{
//		Vector3 forward(1, 0, 0);
//		Vector3 right(0, 1, 0);
//		Vector3 up(0, 0, 1);
//
//		Vector3 v1(0, 23, 12);
//		Vector3 v2(12, 2, 15);
//		auto v = v1.Projection(v2);
//
//		std::cout << v.x << ' ' << v.y << ' ' << v.z << '\n';
//
//		return 0;
//	}
//	Rotator rotator(12, 34, 370);
//	auto vec = RotatorToVector3(rotator);
//	std::cout << "Rotator makes unit vector: vec.Length() == " << vec.Length() << '\n';
//
//	return 0;
//}
#include <iostream>
#include "Math.h"
#include "Render/tgaimage.h"
#include "Render/geometry.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
const int width = 1920;
const int height = 1080;

void line(Vec2i p0, Vec2i p1, TGAImage& image, TGAColor color) {
    bool steep = false;
    if (std::abs(p0.x - p1.x) < std::abs(p0.y - p1.y)) {
        std::swap(p0.x, p0.y);
        std::swap(p1.x, p1.y);
        steep = true;
    }
    if (p0.x > p1.x) {
        std::swap(p0, p1);
    }

    for (int x = p0.x; x <= p1.x; x++) {
        float t = (x - p0.x) / (float)(p1.x - p0.x);
        int y = p0.y * (1. - t) + p1.y * t;
        if (steep) {
            image.set(y, x, color);
        }
        else {
            image.set(x, y, color);
        }
    }
}

Vec2i Vector3ToVec2i(const Vector3& v)
{
    return Vec2i((v.x + 1.) * width / 2., (v.y + 1.) * height / 2.);
}

int main(int argc, char** argv)
{
    TGAImage image(width, height, TGAImage::RGB);

    Vector3 forward(1, 0, 0);
    Vector3 right(0, 1, 0);
    Vector3 up(0, 0, 0);

    Vector3 v1(-1200, 1000, 1200);
    Vector3 v2(1900, 200, 0);
    auto v = v1.Projection(v2);
    std::cout << v.x << ' ' << v.y << ' ' << v.z << '\n';


    //line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(v1), image, red);
    line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(v), image, blue);
    line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(v1), image, red);
    line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(v2), image, green);

    line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(forward), image, white);
    line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(right), image, white);
    line(Vector3ToVec2i(Vector3()), Vector3ToVec2i(up), image, white);

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}


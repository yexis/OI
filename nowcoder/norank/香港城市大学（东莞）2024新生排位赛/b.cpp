#include <bits/stdc++.h>
using namespace std;

struct Vector {
    double x, y, z;
    Vector(double a=0, double b=0, double c=0) : x(a), y(b), z(c) {}

    Vector operator-(const Vector& other) const{
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    Vector cross(const Vector& other) const{
        return Vector(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
        );
    }

    double dot(const Vector& other) const{
        return x * other.x + y * other.y + z * other.z;
    }

    double magnitude() const{
        return sqrt(x * x + y * y + z * z);
    }

    Vector normalize() const{
        double mag = magnitude();
        if (mag == 0) return Vector(0,0,0);
        return Vector(x / mag, y / mag, z / mag);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Vector A, B, C, D;
    cin >> A.x >> A.y >> A.z;
    cin >> B.x >> B.y >> B.z;
    cin >> C.x >> C.y >> C.z;
    cin >> D.x >> D.y >> D.z;

    Vector b0 = B - A;
    Vector b1 = C - B;
    Vector b2 = D - C;

    Vector n1 = b0.cross(b1);
    Vector n2 = b1.cross(b2);
    Vector b1_unit = b1.normalize();
    Vector m1 = n1.cross(b1_unit);
    double x = n1.dot(n2);
    double y = m1.dot(n2);
    double angle_rad = atan2(y, x);
    double angle_deg = angle_rad * 180.0 / M_PI;
    if(angle_deg < 0){
        angle_deg += 360.0;
    }
    if(angle_deg >= 180.0){
        angle_deg = 360.0 - angle_deg;
    }
    int result = int(angle_deg + 0.5);
    if(result == 180){
        result = 0;
    }

    cout << result;
}
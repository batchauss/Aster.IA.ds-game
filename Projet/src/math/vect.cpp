#include "vect.h"
#include <cmath>

Vect::Vect(coord _x,coord _y, coord _z)
	:x(_x), y(_y), z(_z)
	{}


bool Vect::operator==(const Vect & a) const {
	return
		a.getX() == x &&
		a.getY() == y &&
		a.getZ() == z
	;
}

bool Vect::operator!=(const Vect & a) const {
	return
		a.getX() != x ||
		a.getY() != y ||
		a.getZ() != z
	;
}

Vect Vect::operator-(const Vect & a) const {
	return Vect(
		x - a.getX(),
		y - a.getY(),
		z - a.getZ()
	);
}

Vect Vect::operator+(const Vect & a) const {
	return Vect(
		x + a.getX(),
		y + a.getY(),
		z + a.getZ()
	);
}

Vect& Vect::operator+=(const Vect & a) {
	x += a.getX();
	y += a.getY();
	z += a.getZ();
	return *this;
}

Vect& Vect::operator-=(const Vect & a) {
	x -= a.getX();
	y -= a.getY();
	z -= a.getZ();
	return *this;
}

Vect Vect::operator/(coord a) const {
	return Vect(
		x / a,
		y / a,
		z / a
	);
}

Vect Vect::operator*(coord a) const {
	return Vect(
		x * a,
		y * a,
		z * a
	);
}

Vect& Vect::operator*=(coord a) {
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

Vect& Vect::operator/=(coord a) {
	x /= a;
	y /= a;
	z /= a;
	return *this;
}

// Frequent method
coord Vect::mag() const {
	return sqrt( (x*x) + (y*y) + (z*z) );
}

Vect Vect::unit() const {
	coord m = mag();
	return Vect(
		x/m,
		y/m,
		z/m
	);
}

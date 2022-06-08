#pragma once

using coord = float;
class Vect {
private:
	coord x,y,z;

public:
	// Builder
	Vect(coord x,coord y, coord z);
	Vect(const Vect & v) = default;
	~Vect() = default;

	// Getters
	coord getX() const { return x; };
	coord getY() const { return y; };
	coord getZ() const { return z; };

	// Getters aliases
	coord getYaw() const    { return x; };
	coord getPitch() const  { return y; };
	coord getRoll() const   { return z; };


	// Undefined comparator
	bool operator<(const Vect & a) const = delete;
	bool operator>(const Vect & a) const = delete;
	bool operator<=(const Vect & a) const = delete;
	bool operator>=(const Vect & a) const = delete;

	// Defined comparator
	bool operator==(const Vect & a) const;
	bool operator!=(const Vect & a) const;

	// Operation between vector
	Vect operator-(const Vect & a) const;
	Vect operator+(const Vect & a) const;
	Vect& operator+=(const Vect & a);
	Vect& operator-=(const Vect & a);

	// Operation between vector and scalar
	Vect operator/(coord a) const;
	Vect operator*(coord a) const;
	Vect& operator/=(coord a);
	Vect& operator*=(coord a);

	// Frequent method
	coord mag() const;
	Vect unit() const;

};

#include <iostream>

class Geolocator
{
private:
	double x, y;
	std::string address;
public:
	Geolocator(std::string addr)
	{
		address = addr;
	}
	void getGeolocation()
	{
		// Connect to openstreetmap service
		// Use address as input
		// Fetch geolocation data
		// return it to the user
	}
	void getAddress(double coor_x, double coor_y)
	{
		x = coor_x;
		y = coor_y;
		// The opposite of the above logic
	}
}

int main()
{
	std::string address = "Yıldırım, Bursa"
	Geolocator geo(address);
	std::cout << geo.getGeolocation() << std::endl;
	return 0;
};


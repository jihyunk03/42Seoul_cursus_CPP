#include "./Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie_horde;

	zombie_horde = new Zombie[N];
	for (int index = 0; index < N; index++)
		zombie_horde[index].setName(name);
	return (zombie_horde);
}

#include "./Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_horde;
	int		N = 10;

	zombie_horde = zombieHorde(N, "Jihyun");
	for (int i = 0; i < N; i++)
		zombie_horde[i].announce();

	delete [] zombie_horde;

	return (0);
}

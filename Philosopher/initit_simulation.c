void initialize_philovalor(t_simulation *sim, int i)
{
    sim->philosophers[i].id = i + 1;
    sim->philosophers[i].simulation = sim;
    sim->philosophers[i].left_fork = i;
    sim->philosophers[i].right_fork = (i + 1) % sim->num_philosophers;
    sim->philosophers[i].meals_eaten = 0;
    sim->philosophers[i].last_meal_time = get_time_ms();
}


int init_simulation(t_simulation *sim, int argc, char **argv)
{
}
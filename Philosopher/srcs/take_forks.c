#include "../include/philo.h"

void take_leftfork(t_philosopher    *philo)
{
    pthread_mutex_lock(&philo->simulation->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has taken the left fork\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
}
void take_rightfork(t_philosopher   *philo)
{
    pthread_mutex_lock(&philo->simulation->forks[philo->right_fork]);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has taken the right fork\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
}

void drop_forks(t_philosopher *philo)
{
    pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
    pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork]);
}


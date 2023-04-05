#include <iostream>
#include <queue>
#include <random>

int main()
{
    // set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> arrival_dis(0.0, 1.0);
    std::exponential_distribution<double> service_dis(1.0);

    // simulation parameters
    int num_customers;
    double mean_interarrival_time = 0.2;
    double mean_service_time = 0.1;

    // get number of customers from user
    std::cout << "Enter the number of customers: ";
    std::cin >> num_customers;

    // initialize variables and data structures
    std::queue<double> queue;
    double server_time = 0.0;
    double total_waiting_time = 0.0;
    double total_service_time = 0.0;
    double total_time_between_arrivals = 0.0;
    int num_waiters = 0;

    // run simulation
    for (int i = 0; i < num_customers; ++i) {
        // generate random interarrival time
        double interarrival_time = -mean_interarrival_time * std::log(1.0 - arrival_dis(gen));
        total_time_between_arrivals += interarrival_time;

        // generate service time and update server time
        double service_time = mean_service_time * service_dis(gen);
        total_service_time += service_time;
        server_time = std::max(server_time, (i == 0 ? 0.0 : queue.back())) + service_time;

        // calculate waiting time and add customer to queue
        double waiting_time = std::max(0.0, queue.empty() ? 0.0 : (queue.back() - (i == 0 ? 0.0 : queue.front())));
        total_waiting_time += waiting_time;
        if (waiting_time > 0) {
            num_waiters++;
        }
        queue.push(server_time);

        // print customer information
        std::cout << "Customer " << i << ": arrival time = " << (i == 0 ? 0.0 : queue.back())
                  << ", service time = " << service_time << ", waiting time = " << waiting_time
                  << ", departure time = " << server_time << std::endl;
    }

    // calculate and print performance metrics
    double avg_waiting_time = total_waiting_time / num_customers;
    double avg_service_time = total_service_time / num_customers;
    double avg_time_between_arrivals = total_time_between_arrivals / (num_customers - 1);
    double avg_waiting_time_of_waiters = total_waiting_time / num_waiters;
    double avg_time_in_system = (total_waiting_time + total_service_time) / num_customers;

    std::cout << "Performance Metrics:" << std::endl;
    std::cout << "Average waiting time: " << avg_waiting_time << std::endl;
    std::cout << "Average service time: " << avg_service_time << std::endl;
    std::cout << "Average time between arrivals: " << avg_time_between_arrivals << std::endl;
    std::cout << "Average waiting time of those who wait: " << avg_waiting_time_of_waiters << std::endl;
    std::cout << "Average time spent in system: " << avg_time_in_system << std::endl;

    return 0;
}

#ifndef HASH_HELPERS_H
#define HASH_HELPERS_H

#include "libraries.h"

namespace utils{
/**
 * In this header are defined inline utils functions.
 */

/**
 * @brief Exception handling function.
 *
 * @param[in] action  Portion of the code that might raise exceptions.
 * @param[in] context Reference to the point of the code where the exception
 * arises.
 */
inline void handleExceptions(const std::function<void()> &action,
                             const std::string &context) {

  try {
    action();
  } catch (const json::exception &e) {
    std::cerr << "Error parsing in  " << context << ": " << e.what()
              << std::endl;
    exit(1);
  } catch (const std::runtime_error &e) {
    std::cerr << "Runtime error in " << context << ": " << e.what()
              << std::endl;
    exit(1);
  } catch (...) {
    std::cerr << "Unknown error in " << context << std::endl;
    exit(1);
  }
}

/**
 * @brief Random number generator.
 *
 * This function provides access to a globally initialized random number generator 
 * to ensure consistent and efficient random number generation across the program.
 *
 * @return Reference to a `std::mt19937` random number generator.
 */
inline std::mt19937& rng() {
    static std::random_device rd;  // Seed generator
    static std::mt19937 gen(rd()); // Mersenne Twister generator
    return gen;
}

/**
 * @brief Generates a random double between [0, 1).
 * 
 * This function uses a uniform distribution to generate a random value 
 * between 0 and 1 using the globally initialized RNG.
 *
 * @return A random double between 0 and 1.
 */
inline double randomDouble() {
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(rng());
}

/**
 * @brief Template function to print vectors of type T. 
 *
 * @param[in] vec  Vector to be printed.
 * @param[in] os   Output stream where the vector will be printed, default is the terminal.
 */
template <typename T>
void printVector(
  const std::vector<T>& vec,
  std::ostream& os = std::cout) {

  for (const T& element : vec) {
    os << element << " ";
  }
  os << std::endl;
}

/**
 * @brief Save the average of a scalar variable to a file. Used to save the
 * average energy and its powers.
 *
 * @param[in] file_name   Where you write the average.
 * @param[in] value       Sum of the values of the observables over the average
 * MC steps.
 * @param[in] T           Temperature at which the average is calculated.
 * @param[in] mcs_av      Number of MC steps over which the average is
 * calculated.
 * @param[in] context     Portion of the code where you try to save the average.
 */
inline void saveScalarAverageToFile(std::string file_name, double value,
                                    double T, int mcs_av, const std::string &context) {

  std::ofstream file;
  file.open(file_name, std::ios::app);
  handleExceptions(
      [&]() {
        if (file.is_open()) {
          file << T << " " << value / mcs_av << std::endl;
          file.close();
        } else {
          throw std::runtime_error("Could not create " + file_name);
        }
      },
      context);
}

/**
 * @brief Function to create a file at a given path.
 *
 * @param[in] file_name  Path of the file.
 * @param[in] context    Reference to the point of the code where you try to
 * create the file.
 */
inline void createFile(std::string file_name, const std::string &context) {

  std::ofstream file(file_name);
  handleExceptions(
      [&]() {
        if (file.is_open()) {
          file.close();
        } else {
          throw std::runtime_error("Could not create " + file_name);
        }
      },
      context);
}


}
#endif // HASH_HELPERS_H

#include <iostream>
#include <vector>

std::vector<uint32_t> read_input(const uint32_t & row_length){
    /*Function in which the user defines the length of the vector
    and push all numbers in it.*/

    std::vector<uint32_t> numbers;

    numbers.reserve(row_length);

    for (uint32_t i = 0; i < row_length; ++i) {
        std::cin >> numbers[i];
    }

    return numbers;
}

void print_result(std::vector<uint32_t> & list_of_numbers){
    /*Function, which print all numbers in vector.*/

    for(const auto & num : list_of_numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::vector<uint32_t> action_with_vector(std::vector<uint32_t> & list_of_numbers, uint32_t & k){
    /*Function, that calculate which number must be removed.*/

    uint32_t current = k;

    print_result(list_of_numbers);

    list_of_numbers.erase(list_of_numbers.begin());

    print_result(list_of_numbers);

    if(list_of_numbers.size() < 2){
        std::cout << "There are no people for Iosif's gangster band." << std::endl;
    }
    else {
        while (list_of_numbers.size() != 2){
            if(current - 1 < list_of_numbers.size()){
                current -= 1;
                list_of_numbers.erase(list_of_numbers.begin() + (current));
                current += k;
            }
            else {
                current = k - 1;
                list_of_numbers.erase(list_of_numbers.begin() + (current));
            }
            print_result(list_of_numbers);
        }
    }

    return list_of_numbers;
}

int main()
{

    uint32_t row_length = 0;
    uint32_t k = 0;

    std::cin >> row_length >> k;

    std::vector<uint32_t> list_of_numbers = read_input(row_length);

    list_of_numbers = action_with_vector(list_of_numbers, k);

    list_of_numbers.shrink_to_fit();

    return 0;
}

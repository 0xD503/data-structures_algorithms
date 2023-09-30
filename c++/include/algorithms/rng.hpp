#pragma once

#include <random>


//template<typename T>
class RNG {
    public:
        RNG(std::mt19937::result_type min, std::mt19937::result_type max);
        //~RNG()

        inline std::mt19937::result_type operator() () {
            return (distribution__(randomGenEngine__));
        }

    private:
        std::random_device device__{};
        std::mt19937 randomGenEngine__;
        std::uniform_int_distribution<std::mt19937::result_type> distribution__;
};

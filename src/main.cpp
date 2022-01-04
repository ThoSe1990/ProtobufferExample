
#include <iostream>

#include "proto/Animal.pb.h"
 
int main(int argc, char* argv[])
{
    Animal message;
    message.set_species("Cat");
    message.set_name("Tiffany");
    message.set_age(12);

    std::cout << "created proto message with animal:\n"
        << "species: " << message.species() << '\n'
        << "name: " << message.name() << '\n'
        << "age: " << message.age() << '\n';

    return 0;
}



// cpp tomorrow night
// cmake gruvbox dark

// conan remote add bincrafters https://bincrafters.jfrog.io/artifactory/api/conan/public-conan
// conan config set general.revisions_enabled=1
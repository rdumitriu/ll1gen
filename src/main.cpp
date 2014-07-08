#include <fstream>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "spec_parser.hpp"
#include "json_generator.hpp"

int main(int argc, char* argv[]) {
    std::string home;
    std::string input;
    std::string dest;
    boost::program_options::options_description desc("Command-line options");
    desc.add_options()
        ("help", "Produces this help message.")
        ("home,h", boost::program_options::value<std::string>()->required(),
                   "Specifies the home directory")
        ("file,f", boost::program_options::value<std::string>()->required(),
                   "Specifies the beans file - input")
        ("destination,d", boost::program_options::value<std::string>()->required(),
                   "Specifies the destination directory")
    ;

    try {
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help") || vm.empty()) {
            std::cout << desc << std::endl;
            return 1;
        }


        if(vm.count("home")) {
            home = vm["home"].as<std::string>();
        } else {
            std::cout << desc << std::endl;
            return 1;
        }
        if(vm.count("file")) {
            input = vm["file"].as<std::string>();
        } else {
            std::cout << desc << std::endl;
            return 1;
        }
        if(vm.count("destination")) {
            dest = vm["destination"].as<std::string>();
        } else {
            std::cout << desc << std::endl;
            return 1;
        }
    } catch( ... ) {
        std::cout << desc << std::endl;
        return 1;
    }

    ll1gen::Specification spec;
    ll1gen::SpecificationParser parser(spec);

    boost::filesystem::path inputPath(input);
    inputPath = boost::filesystem::absolute(inputPath);
    if(!boost::filesystem::exists(inputPath) || !boost::filesystem::is_regular_file(inputPath)) {
        std::cout << "Could not find specification file: " << input;
        return 1;
    }

    std::fstream is(inputPath.c_str(), std::fstream::in);
    if(!is) {
        std::cout << "Could not open specification file: " << input;
        return 1;
    }
    if(!parser.parse(is)) {
        parser.printErrors();
        return 1;
    }

    ll1gen::JsonGenerator generator(spec, home, dest);
    if(!generator.generate()) {
        generator.printErrors();
        return 1;
    }

    return 0;
}

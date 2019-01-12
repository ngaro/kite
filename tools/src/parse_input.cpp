/****************************************************************/
/*                                                              */
/*  Copyright (C) 2018, M. Andelkovic, L. Covaci, A. Ferreira,  */
/*                    S. M. Joao, J. V. Lopes, T. G. Rappoport  */
/*                                                              */
/****************************************************************/

#include <iostream>
#include <Eigen/Dense>
//#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include "ComplexTraits.hpp"
#include "H5Cpp.h"
#include "myHDF5.hpp"
#include "macros.hpp"
#include "parse_input.hpp"


void shell_input::printDC(){

    // DC Conductivity
    std::cout << "Printing parameters for the DC conductivity obtained from the shell:\n";
    if(CondDC_Temp != -1)           std::cout << "    temperature: "                << CondDC_Temp << "\n";
    if(CondDC_NumEnergies != -1)    std::cout << "    number of energy points: "    << CondDC_NumEnergies << "\n";
    if(CondDC_Scat != -8888)        std::cout << "    scattering parameter: "       << CondDC_Scat << "\n";
    if(CondDC_FermiMin != -8888)    std::cout << "    minimum Fermi energy: "       << CondDC_FermiMin << "\n";
    if(CondDC_FermiMax != -8888)    std::cout << "    maximum Fermi energy: "       << CondDC_FermiMax << "\n";
    if(CondDC_NumFermi != -1)       std::cout << "    number of Fermi energies: "   << CondDC_NumFermi << "\n";
    if(CondDC_Name != "")           std::cout << "    name of the output file: "    << CondDC_Name << "\n";
    if(CondDC_Exclusive == true)    std::cout << "    Exclusive.\n";
    std::cout << "\n";
} 
void shell_input::printOpt(){
    std::cout << "Printing parameters for the Optical Conductivity obtained from the shell:\n";
    if(CondOpt_Temp != -8888)       std::cout << "    temperature: "                << CondOpt_Temp << "\n";
    if(CondOpt_NumEnergies != -1)   std::cout << "    number of energy points: "    << CondOpt_NumEnergies << "\n";
    if(CondOpt_Scat != -8888)       std::cout << "    scattering parameter: "       << CondOpt_Scat << "\n";
    if(CondOpt_FreqMin != -8888)    std::cout << "    minimum frequency: "          << CondOpt_FreqMin << "\n";
    if(CondOpt_FreqMax != -8888)    std::cout << "    maximum frequency: "          << CondOpt_FreqMax << "\n";
    if(CondOpt_NumFreq != -1)       std::cout << "    number of frequencies: "      << CondOpt_NumFreq << "\n";
    if(CondOpt_Fermi != -8888)      std::cout << "    number of Fermi energies: "   << CondOpt_Fermi << "\n";
    if(CondOpt_Name != "")          std::cout << "    name of the output file: "    << CondOpt_Name << "\n";
    if(CondOpt_Exclusive == true)   std::cout << "    Exclusive.\n";
    std::cout << "\n";
}

void shell_input::printOpt2(){
    std::cout << "Printing parameters for the Second-Order Optical conductivity obtained from the shell:\n";
    if(CondOpt2_Temp != -8888)      std::cout << "    temperature: "                << CondOpt2_Temp << "\n";
    if(CondOpt2_NumEnergies != -1)  std::cout << "    number of energy points: "    << CondOpt2_NumEnergies << "\n";
    if(CondOpt2_ratio != -8.8888)   std::cout << "    ratio of frequencies: "       << CondOpt2_ratio << "\n";
    if(CondOpt2_print_all != -2)    std::cout << "    Print all: "                  << CondOpt2_print_all << "\n";
    if(CondOpt2_Scat != -8888)      std::cout << "    scattering parameter: "       << CondOpt2_Scat << "\n";
    if(CondOpt2_FreqMin != -8888)   std::cout << "    minimum frequency: "          << CondOpt2_FreqMin << "\n";
    if(CondOpt2_FreqMax != -8888)   std::cout << "    maximum frequency: "          << CondOpt2_FreqMax << "\n";
    if(CondOpt2_NumFreq != -1)      std::cout << "    number of frequencies: "      << CondOpt2_NumFreq << "\n";
    if(CondOpt2_Fermi != -8888)     std::cout << "    number of Fermi energies: "   << CondOpt2_Fermi << "\n";
    if(CondOpt2_Name != "")         std::cout << "    name of the output file: "    << CondOpt2_Name << "\n";
    if(CondOpt2_Exclusive == true)  std::cout << "    Exclusive.\n";
    std::cout << "\n";
}

void shell_input::printDOS(){
    std::cout << "Printing parameters for the Density of States obtained from the shell:\n";
    if(DOS_NumEnergies != -1 )      std::cout << "    number of energy points: "    << DOS_NumEnergies << "\n";
    if(DOS_Name != "")              std::cout << "    name of the output file: "    << DOS_Name << "\n";
    if(DOS_Exclusive == true)       std::cout << "    Exclusive.\n";
    std::cout << "\n";
}

void shell_input::printlDOS(){
    std::cout << "Printing parameters for the Local Density of States obtained from the shell:\n";
    if(lDOS_Name != "")              std::cout << "    name of the output file: "    << lDOS_Name << "\n";
    if(lDOS_Exclusive == true)       std::cout << "    Exclusive.\n";
    std::cout << "\n";
}

void shell_input::printHelp(){
    std::cout << "KITE-Tools command-line configuration guide. Basic usage:\n\n";
    std::cout << ".KITE-tools h5_file.h5 [options]\n";
    std::cout << "--help -h    Prints this message\n\n";
    std::cout << "When run without any more options, KITE-tools will simply read through the h5_file.h5 hdf5 file and find out what needs to be calculated. It will then proceed to calculate all the quantities present in that configuration file using the parameters in that same file, together with some defaults present in the source code. When given options, KITE-tools will still calculate all the quantities requested by the .h5 configuration file, but those parameters may be changed.\n\n";
    std::cout << "There are four main parameters which may be configured. Each of these has several subparameters associated with them. The main parameters are:\n\n";
    std::cout << "--DOS        Density of states\n";
    std::cout << "--LDOS       Local density of states\n";
    std::cout << "--CondDC     DC conductivity\n";
    std::cout << "--CondOpt    Optical conductivity\n";
    std::cout << "--CondOpt2   Second-order optical conductivity (photoconductivity)\n\n";
    std::cout << "After each of these keywords, the program will be expecting the subparameters associated with that word (always separated by spaces):\n\n";
    std::cout << "--LDOS     -N              Name of the output file\n";
    std::cout << "           -X              Exclusive. Only calculate this quantity\n\n";
    std::cout << "--DOS      -E              Number of energy points\n";
    std::cout << "           -N              Name of the output file\n";
    std::cout << "           -X              Exclusive. Only calculate this quantity\n\n";
    std::cout << "--CondDC   -E              Number of energy points used in the integration\n";
    std::cout << "           -T              Temperature\n";
    std::cout << "           -S              Broadening parameter of the Green's functions\n";
    std::cout << "           -F min max num  Fermi energies. min and max may be ommited.\n";
    std::cout << "           -N              Name of the output file\n";
    std::cout << "           -X              Exclusive. Only calculate this quantity\n\n";
    std::cout << "--CondOpt  -E              Number of energy points used in the integration\n";
    std::cout << "           -T              Temperature\n";
    std::cout << "           -S              Broadening parameter of the Green's functions\n";
    std::cout << "           -O min max num  Frequencies\n";
    std::cout << "           -F              Fermi energy\n";
    std::cout << "           -N              Name of the output file\n";
    std::cout << "           -X              Exclusive. Only calculate this quantity\n\n";
    std::cout << "--CondOpt2 -E              Number of energy points used in the integration\n";
    std::cout << "           -R              Ratio of the second frequency relative to the first: w2 = R*w1\n";
    std::cout << "           -P              if set to 1: writes all the terms to separate files\n";
    std::cout << "           -T              Temperature\n";
    std::cout << "           -S              Broadening parameter of the Green's functions\n";
    std::cout << "           -O min max num  Frequencies\n";
    std::cout << "           -F              Fermi energy\n";
    std::cout << "           -N              Name of the output file\n";
    std::cout << "           -X              Exclusive. Only calculate this quantity\n\n";
    std::cout << "All the quantities are in the same units as the ones in the python configuration script. All quantities are double-precision numbers except for the ones representing integers, such as the numbers of points.\n\n";
    std::cout << "Examples:\n\n";
    std::cout << "Example 1\n";
    std::cout << "    ./KITE-tools h5_file.h5 --DOS -E 1024\n";
    std::cout << "    Processes the .h5 file as usual but ignores the number of energy points in the density of states present there. Instead, KITE-tools will use the value 1024 as soecified in the example.\n\n";
    std::cout << "Example 2\n";
    std::cout << "    ./KITE-tools h5_file.h5 --CondDC -E 552 -S 0.01\n";
    std::cout << "    Processes the .h5 file but uses 552 points for the energy integration and a broadening parameter of 0.01.\n\n";
    std::cout << "Example 3\n";
    std::cout << "    ./KITE-tools h5_file.h5 --CondDC -T 0.4 -F 500\n";
    std::cout << "    Calculates the DC conductivity using a temperature of 0.4 and 500 equidistant Fermi energies spanning the spectrum of the Hamiltonian.\n\n";
    std::cout << "Example 4\n";
    std::cout << "    ./KITE-tools h5_file.h --CondDC -F -1.2 2.5 30 --CondOpt -T 93\n";
    std::cout << "    Calculates the DC conductivity using 30 equidistant Fermi energies in the range [-1.2, 2.5] and the optical conductivity using a temperature of 93.\n";
    std::cout << "\n";
    std::cout << "Copyright (C) 2018, M. Andelkovic, L. Covaci, A. Ferreira, S. M. Joao, J. V. Lopes, T. G. Rappoport\n\n";
    std::cout << "This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n\n";
    std::cout << "This program is distributed in the hope that it will be useful but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n";
    }




shell_input::shell_input(){};

shell_input::shell_input(int argc, char *argv[]){
	// Processes the input that this program recieves from the command line	

    // First, find the position of each of the following functions:
    valid_keys = std::vector<std::string>{"--DOS", "--CondOpt","--CondDC", "--CondOpt2", "--LDOS"};
    len = valid_keys.size();   // length of valid_keys?
    keys_pos = std::vector<int>(len, -1);
    keys_len = std::vector<int>(len, -1);

    int m = 0;
    for(int i = argc-1; i >= 0; i--){
        m++;
        std::string arguments = std::string(argv[i]);
        for(int j = 0; j < len; j++){
            if(arguments == "--help" or arguments == "-h"){
                printHelp();
                exit(0);
            }

            if(arguments == valid_keys.at(j)){
                keys_pos.at(j) = i;
                keys_len.at(j) = m-1;
                m = 0;
                break;
            }
        }
    }


    // Run the input through each of these functions to find the relevant 
    // parameters to each of them
    parse_CondDC(argc, argv);
    parse_DOS(argc, argv);
    parse_lDOS(argc, argv);
    parse_CondOpt(argc, argv);
    parse_CondOpt2(argc, argv);

    // Process the exclusive flag. If there are no exclusive functions, 
    // all will be calculated. If there's only one, that's the only one
    // that needs to be calculated. Furthermore, we need to check
    // whether there is only one exclusive flag
    CondDC_is_required = false;
    CondOpt_is_required = false;
    CondOpt2_is_required = false;
    DOS_is_required = false;
    lDOS_is_required = false;

    int num_exclusives = get_num_exclusives();
    if(num_exclusives > 1){
        std::cout << "There can be only one exclusive function. Exiting.\n";
        exit(1);
    } else {
        if(num_exclusives == 1){
            if(CondDC_Exclusive) CondDC_is_required = true;
            if(CondOpt_Exclusive) CondOpt_is_required = true;
            if(CondOpt2_Exclusive) CondOpt2_is_required = true;
            if(DOS_Exclusive) DOS_is_required = true;
            if(lDOS_Exclusive) lDOS_is_required = true;

        } else {
            CondDC_is_required = true;
            CondOpt_is_required = true;
            CondOpt2_is_required = true;
            DOS_is_required = true;
            lDOS_is_required = true;
            }
    }

};

int shell_input::get_num_exclusives(){
    int N_exclusives = 0;
    if(CondDC_Exclusive)      N_exclusives++;
    if(CondOpt_Exclusive)     N_exclusives++;
    if(CondOpt2_Exclusive)    N_exclusives++;
    if(DOS_Exclusive)         N_exclusives++;
    if(lDOS_Exclusive)        N_exclusives++;

    return N_exclusives;
};

void shell_input::parse_CondDC(int argc, char *argv[]){
    // This function looks at the command-line input pertaining to CondDC and
    // finds the parameters for the temperature "t", number of energy points "E", 
    // scattering parameter "S" and Fermi energy min, max and num "F"
    
    CondDC_Temp = -1;
    CondDC_NumEnergies = -1;
    CondDC_FermiMin = -8888; // Some stupid values that I hope no-one will ever pick
    CondDC_FermiMax = -8888;
    CondDC_NumFermi = -1;
    CondDC_Scat = -8888;
    CondDC_Name = "";
    CondDC_Exclusive = false;
    // Process CondDC
    int j = 2;
    int pos = keys_pos.at(j);
    if(pos != -1){
        for(int k = 1; k < keys_len.at(j); k++){
            std::string name = argv[k + pos];
            std::string n1 = argv[k + pos + 1];

            if(name == "-T")
                CondDC_Temp = atof(n1.c_str());
            if(name == "-E")
                CondDC_NumEnergies = atoi(n1.c_str());
            if(name == "-S")
                CondDC_Scat = atof(n1.c_str());
            if(name == "-N")
                CondDC_Name = n1;
            if(name == "-X" or n1 == "-X")
                CondDC_Exclusive = true;
            if(name == "-F"){
                if(k == keys_len.at(j) - 1){
                    CondDC_NumFermi = atoi(n1.c_str());
                    continue;
                } else {
                    std::string n2 = argv[k + pos + 2];
                    if(n2 == "-T" or n2 == "-E" or n2 == "-F" or n2 == "-S" or n2 == "-N" or n2 == "-X"){
                        CondDC_NumFermi = atoi(n1.c_str());
                    } else {
                        std::string n3 = argv[k + pos + 3];
                        CondDC_FermiMin = atof(n1.c_str());
                        CondDC_FermiMax = atof(n2.c_str());
                        CondDC_NumFermi = atoi(n3.c_str());
                    }
                }
            }
        }
    }
}

void shell_input::parse_CondOpt(int argc, char* argv[]){
    // This function looks at the command-line input pertaining to CondOpt and
    // finds the parameters for the temperature "t", number of energy points "E", 
    // scattering parameter "S", Fermi energy "F" and min_freq, max_freq, num_freqs "O"
    
    CondOpt_Temp = -8888;
    CondOpt_NumEnergies = -1;
    CondOpt_FreqMin = -8888; // Some stupid values that I hope no-one will every pick
    CondOpt_FreqMax = -8888;
    CondOpt_NumFreq = -1;
    CondOpt_Fermi = -8888;
    CondOpt_Scat = -8888;
    CondOpt_Exclusive = false;
    CondOpt_Name = "";

    // Process CondOpt
    int j = 1;
    int pos = keys_pos.at(j);
    if(pos != -1){
        for(int k = 1; k < keys_len.at(j); k++){
            std::string name = argv[k + pos];
            std::string n1 = argv[k + pos + 1];

            if(name == "-T")
                CondOpt_Temp = atof(n1.c_str());
            if(name == "-E")
                CondOpt_NumEnergies = atoi(n1.c_str());
            if(name == "-S")
                CondOpt_Scat = atof(n1.c_str());
            if(name == "-N")
                CondOpt_Name = n1;
            if(name == "-F")
                CondOpt_Fermi = atof(n1.c_str());
            if(name == "-X" or n1 == "-X")
                CondOpt_Exclusive = true;
            if(name == "-O"){
                std::string n2 = argv[k + pos + 2];
                std::string n3 = argv[k + pos + 3];
                CondOpt_FreqMin = atof(n1.c_str());
                CondOpt_FreqMax = atof(n2.c_str());
                CondOpt_NumFreq = atoi(n3.c_str());
            }
        }
    }
}

void shell_input::parse_CondOpt2(int argc, char* argv[]){
    // This function looks at the command-line input pertaining to CondOpt2 and
    // finds the parameters for the temperature "t", number of energy points "E", 
    // scattering parameter "S", Fermi energy "F" and min_freq, max_freq, num_freqs "O"
    
    CondOpt2_Temp = -8888;
    CondOpt2_NumEnergies = -1;
    CondOpt2_FreqMin = -8888; // Some stupid values that I hope no-one will ever pick
    CondOpt2_FreqMax = -8888;
    CondOpt2_NumFreq = -1;
    CondOpt2_Fermi = -8888;
    CondOpt2_Scat = -8888;
    CondOpt2_Exclusive = false;
    CondOpt2_ratio = -8.8888;
    CondOpt2_print_all = -2;
    CondOpt2_Name = "";

    // Process CondOpt2
    int j = 3;
    int pos = keys_pos.at(j);
    if(pos != -1){
        for(int k = 1; k < keys_len.at(j); k++){
            std::string name = argv[k + pos];
            std::string n1 = argv[k + pos + 1];

            if(name == "-T")
                CondOpt2_Temp = atof(n1.c_str());
            if(name == "-E")
                CondOpt2_NumEnergies = atoi(n1.c_str());
            if(name == "-R")
                CondOpt2_ratio = atof(n1.c_str());
            if(name == "-P")
                CondOpt2_print_all = atoi(n1.c_str());
            if(name == "-S")
                CondOpt2_Scat = atof(n1.c_str());
            if(name == "-F")
                CondOpt2_Fermi = atof(n1.c_str());
            if(name == "-N")
                CondOpt2_Name = n1;
            if(name == "-X" or n1 == "-X")
                CondOpt2_Exclusive = true;
            if(name == "-O"){
                std::string n2 = argv[k + pos + 2];
                std::string n3 = argv[k + pos + 3];
                CondOpt2_FreqMin = atof(n1.c_str());
                CondOpt2_FreqMax = atof(n2.c_str());
                CondOpt2_NumFreq = atoi(n3.c_str());
            }
        }
    }
}

void shell_input::parse_DOS(int argc, char* argv[]){
    // This function looks at the command-line input pertaining to CondDC and
    // finds the parameters for the temperature "t", number of energy points "E", 
    // scattering parameter "S" and Fermi energy min, max and num "F"
    
    DOS_NumEnergies = -1;
    DOS_Name = "";
    DOS_Exclusive = false;
    int pos = keys_pos.at(0);
    if(pos != -1){
        for(int k = 1; k < keys_len.at(0); k++){
            std::string name = argv[k + pos];
            std::string n1 = argv[k + pos + 1];
            if(name == "-E")
                DOS_NumEnergies = atoi(n1.c_str());
            if(name == "-N")
                DOS_Name = n1;
            if(name == "-X" or n1 == "-X")
                DOS_Exclusive = true;
        }
    }
    DOS_NumEnergies = DOS_NumEnergies; 
    DOS_Name = DOS_Name;
    DOS_Exclusive = DOS_Exclusive;
};


void shell_input::parse_lDOS(int argc, char* argv[]){
    // This function looks at the command-line input pertaining to CondDC and
    // finds the parameters for the temperature "t", number of energy points "E", 
    // scattering parameter "S" and Fermi energy min, max and num "F"
    
    lDOS_Name = "";
    lDOS_Exclusive = false;
    int pos = keys_pos.at(4);
    if(pos != -1){
        for(int k = 1; k < keys_len.at(4); k++){
            std::string name = argv[k + pos];
            std::string n1 = argv[k + pos + 1];
            if(name == "-N")
                lDOS_Name = n1;
            if(name == "-X" or n1 == "-X")
                lDOS_Exclusive = true;
        }
    }
    lDOS_Name = lDOS_Name;
    lDOS_Exclusive = lDOS_Exclusive;
}
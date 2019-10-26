void print_header_message(){
  verbose_message( R"ENDSTRING(
+------------------------------------------------------------------------+
|            Chebyshev Polynomial Green's Function Approach              |
|             to Real-Space Quantum Transport Simulations                |
|                                                                        |
|                     KITE | Release 1.0                                 |
|                     Kite home: quantum-kite.com                        |
|                                                                        |
|    Created by Simao M. Joao, Joao V. Lopes (Universidade do Porto),    |
|      Tatiana G. Rappoport (Universidade Federal Rio de Janeiro),       |
|        Misa Andelkovic, Lucian Covaci (University of Antwerp)          |
|                and Aires Ferreira (University of York)                 |
|                                                                        |
|            Funded by The Royal Society | royalsociety.org              |
|                                                                        |
|  Copyright (C) 2018, 2019, M. Andelkovic, L. Covaci, A. Ferreira,      |
|                      S. M. Joao, J. V. Lopes, T. G. Rappoport          |
|                                                                        |
|  This program is free software: you can redistribute it and/or modify  |
|  it under the terms of the GNU General Public License as published by  |
|  the Free Software Foundation, either version 3 of the License, or     |
|  (at your option) any later version.                                   |
|                                                                        |
|  This program is distributed in the hope that it will be useful,       |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of        |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  |
|  See the GNU General Public License for more details.                  |
+------------------------------------------------------------------------+
)ENDSTRING" );

}

void print_flags_message(){
  verbose_message("------- FLAGS SET -------\n");
  verbose_message("Flags set at compilation:\n");
  verbose_message("DEBUG: "); verbose_message(DEBUG); verbose_message("\n");
  verbose_message("VERBOSE: "); verbose_message(VERBOSE); verbose_message("\n");
  verbose_message("ESTIMATE_TIME: "); verbose_message(ESTIMATE_TIME); verbose_message("\n");
  verbose_message("-------------------------\n");
}

void print_info_message(){
  verbose_message( R"ENDSTRING(
------------------------------ INFORMATION ------------------------------
Linear response functions in units of e^2/h.
To stop these messages, set VERBOSE to 0 in the Makefile.
To see debug messages, set DEBUG to 1 in the Makefile.
To estimate the calculation time, set ESTIMATE_TIME to 1 in the Makefile.
-------------------------------------------------------------------------

)ENDSTRING" );
}

void print_welcomescreen(){ print_header_message(); print_info_message(); print_flags_message(); }

void fatal(unsigned int errorcode, const char** extrainfo) {
  std::cerr << "Problem: ";
  switch(errorcode) {
  case 1:
    std::cerr << "No configuration file found";
    break;
  case 2: //No --help argument yet, maybe useful later...
    std::cerr << "No arguments given, you might want to try running \"" << extrainfo[0] << " --help\"";
    break;
  case 3:
    std::cerr << "Can't read HDF5 file '" << extrainfo[0] << "': (" << extrainfo[1] << ")";
    break;
  default:
    std::cerr << "Unknown error";
  }
  std::cerr << "\nExiting.\n";
  exit(errorcode);
}

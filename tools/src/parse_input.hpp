
class shell_input{
    // Set of parameters that may be passed through the shell

    public:
        // DC conductivity
        double CondDC_Temp; 
        int CondDC_NumEnergies; 
        double CondDC_Scat; 
        double CondDC_FermiMin; 
        double CondDC_FermiMax; 
        int CondDC_NumFermi; 
        std::string CondDC_Name;
        bool CondDC_Exclusive;
        bool CondDC_is_required;

        // Optical Conductivity
        double CondOpt_Temp; 
        int CondOpt_NumEnergies; 
        double CondOpt_Scat; 
        double CondOpt_Fermi; 
        double CondOpt_FreqMin; 
        double CondOpt_FreqMax; 
        int CondOpt_NumFreq; 
        std::string CondOpt_Name;
        bool CondOpt_Exclusive;
        bool CondOpt_is_required;


        // Density of states
        int DOS_NumEnergies;
        std::string DOS_Name;
        bool DOS_Exclusive;
        bool DOS_is_required;

        // Local density of states
        std::string lDOS_Name;
        bool lDOS_Exclusive;
        bool lDOS_is_required;

        // 2nd order optical conductivity
        double CondOpt2_Temp; 
        int CondOpt2_NumEnergies; 
        double CondOpt2_Scat; 
        double CondOpt2_Fermi; 
        double CondOpt2_FreqMin; 
        double CondOpt2_FreqMax; 
        int CondOpt2_NumFreq; 
        std::string CondOpt2_Name;
        bool CondOpt2_Exclusive;
        bool CondOpt2_is_required;
        double CondOpt2_ratio;
        int CondOpt2_print_all;

        // Help menu
        bool help;

        // function names
        std::vector<std::string> valid_keys;
        int len;
        std::vector<int> keys_pos;
        std::vector<int> keys_len;

        shell_input(int, char**);
        shell_input();
        void printHelp();
        void printDC();
        void printOpt();
        void printOpt2();
        void printDOS();
        void printlDOS();

        void parse_CondDC(int argc, char *argv[]);
        void parse_CondOpt(int argc, char *argv[]);
        void parse_CondOpt2(int argc, char *argv[]);
        void parse_DOS(int argc, char *argv[]);
        void parse_lDOS(int argc, char *argv[]);
        int get_num_exclusives();

};
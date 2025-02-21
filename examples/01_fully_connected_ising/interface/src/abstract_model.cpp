#include "abstract_model.h"

namespace abstract_model_space {

    Model::Model(const std::string &input_folder) {

        /** Implemented in the real model (see `include/model/parameters.h`). */ 
        real_model_space::parseParameters(_parameters, input_folder);

         /** Implemented in the real model (see `include/model/interactions.h`). */    
        real_model_space::initializeInteractions(_interactions, _parameters, input_folder);

        /** Implemented in the real model (see `include/model/state.h`). */ 
        real_model_space::initializeState(_state, _interactions, _parameters, input_folder);

    }

    void Model::printModelParameters() {

        /** Implemented in the real model (see `include/model/parameters.h`). */ 
        real_model_space::printParameters(_parameters);
    }


    void Model::printModelInteractions() {

        /** Implemented in the real model (see `include/model/interactions.h`). */ 
        real_model_space::printInteractions(_interactions);
    }
 
    void Model::printModelState() {

        /** Implemented in the real model (see `include/model/state.h`). */ 
        real_model_space::printState(_state);
    }

    void Model::saveModelState(const std::string &state_output) {

        /** Implemented in the real model (see `include/model/state.h`). */ 
        real_model_space::saveState(_state,  state_output);
    }

    void Model::printModelEnergy() {

        /** Implemented in the real model (see `include/model/state.h`). */ 
        real_model_space::printEnergy(_state);
    }

   void Model::updateModelSystem(double T) {

        /** Implemented in the real model (see `include/model/update.h`). */ 
        real_model_space::updateSystem(_state, _interactions, _parameters, T);
    }

    void Model::initializeModelAverages(const std::string &average_output) {

        /** Implemented in the real model (see `include/model/averages.h`). */ 
        real_model_space::initializeAverages(_averages, _parameters, average_output);
    }

    void Model::updateModelAverages() {

        /** Implemented in the real model (see `include/model/averages.h`). */ 
        real_model_space::updateAverages(_averages, _state, _parameters);
    }

    void Model::saveModelAverages(double T, int mcs_av,const std::string &average_output) {

        /** Implemented in the real model (see `include/model/averages.h`). */ 
        real_model_space::saveAverages(_averages, _parameters, T, mcs_av, average_output);
    }

} 

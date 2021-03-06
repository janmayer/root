// @(#)root/tmva $Id$
// Author: Saurav Shekhar 02/08/17

/*************************************************************************
 * Copyright (C) 2017, Saurav Shekhar                                    *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

////////////////////////////////////////////////////////////////////
//Testing RNNLayer for incrementing a number                      //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include "TestFullRNN.h"
// order is important
#include "TMVA/DNN/Architectures/TCudnn.h"

using namespace TMVA::DNN;
using namespace TMVA::DNN::RNN;


int main() {
   TString rnnType = "RNN";

   using Architecture_t = TCudnn<Double_t>;

   std::cout << "Training RNN to identity first";

   //testFullRNN(size_t batchSize, size_t stateSize, size_t inputSize, size_t outputSize)
   // reconstruct 8 bit vector
   bool iret = true;
   bool debug = false;
   // batchsize, statesize, inputsize, outputsize (timesteps = 1 fixed)
   iret &= testFullRNN<Architecture_t>(rnnType,2, 3, 2, 2, debug) ;

   // test a full RNN with 5 time steps and different signal/backgrund time dependent shapes
   // batchsize, statesize , inputsize, seed
   int seed = 111;
   std::cout << "Training RNN to simple time dependent data " << std::endl;
   debug = false;
   iret &= testFullRNN2<Architecture_t>(rnnType, 64, 10, 5, seed, debug);

   return iret ? 0 : -1;
}

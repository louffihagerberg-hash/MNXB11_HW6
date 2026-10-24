#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include "MovingObject.h"
void write(){
    const Int_t nMeasurements = 10000;
    gRandom->SetSeed(55555);
    MovingObject* obj = new MovingObject();
    TFile* file = new TFile("tree_file.root", "RECREATE");
    TTree* tree = new TTree("tree", "Velocity measurements");
    tree->Branch("MovingObject", "MovingObject", &obj);
    for (Int_t i = 0; i < nMeasurements; ++i) {
        Double_t vx = gRandom->Gaus(0.0, 1.50);
        Double_t vy = gRandom->Gaus(0.0, 1.50);
        Double_t vz = gRandom->Gaus(0.0, 1.50);

        obj->SetVelocity(vx, vy, vz);

        tree->Fill();
    }

    file->Write();

    file->Close();

    delete obj;
    delete file;

}
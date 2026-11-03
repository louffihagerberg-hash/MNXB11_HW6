void read() {
    TFile *file = TFile::Open("tree_file.root", "READ");
    TTree *tree = nullptr;
    file->GetObject("tree", tree);

    TCanvas *c1 = new TCanvas("c1", "Velocity plots", 1200, 500);
    c1->Divide(2, 1);

    tree->Print();

    c1->cd(1);
    tree->Draw(
    "sqrt(MovingObject.fVx*MovingObject.fVx + MovingObject.fVy*MovingObject.fVy):MovingObject.fVz",
    "sqrt(MovingObject.fVx*MovingObject.fVx + MovingObject.fVy*MovingObject.fVy + MovingObject.fVz*MovingObject.fVz) > 0.50",
    ""
    );

    c1->cd(2);

    MovingObject *obj = nullptr;
    tree->SetBranchAddress("MovingObject", &obj);

    TH2D *h2 = new TH2D(
        "h2",
        "Horizontal velocity comparison;x-Velocity v_{x} (m/s);y-Velocity v_{y} (m/s)",
        100, -1.5, 1.5,
        100, -1.5, 1.5
    );

    for (int i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);

        h2->Fill(obj->Vx(), obj->Vy());
    }

    h2->Draw("COLZ");
}
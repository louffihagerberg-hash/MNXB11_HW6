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
    TH1 *h = (TH1*)gPad->GetPrimitive("htemp");
    h->SetTitle("Horizontal Speed/Z-axis velocity;z-Velocity v_{z} (m/s);Horizontal Speed v_{xy} (m/s)");

    c1->cd(2);
    tree->Draw("fVy:fVx>>h2(100,-5,5,100,-5,5)", "", "COLZ");
    TH1 *h2 = (TH1*)gPad->GetPrimitive("htemp");
    h2->SetTitle("Horisontal velocity comparison; x-Velocity v_{x} (m/s); y-Velocity v_{y} (m/s)");
}
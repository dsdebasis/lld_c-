#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class DocumentEditor{
private:
       vector<string> documentElemnets;
       string renderedDocument;
public:
       void addText(string text){
        documentElemnets.push_back(text);
       }

       void addImage(string imagePath){
        documentElemnets.push_back(imagePath);

       }
       
       string renderDocument(){
        if(renderedDocument.empty()){
            string result;

            for(auto element : documentElemnets){
              if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                 element.substr(element.size() - 4) == ".png")) {
                    result += "[Image: " + element + "]" + "\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile(){
      ofstream file("document.txt");
        if (file.is_open()) {
            file << renderDocument();
            file.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};


int main(){
    DocumentEditor editor;
    editor.addText("Hello, this is a document.");
    editor.addImage("image.jpg");
    editor.saveToFile();
    return 0;
}
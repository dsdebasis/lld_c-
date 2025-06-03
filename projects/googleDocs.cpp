#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
class Document{
    public:
    string documentName;
    virtual string render()=0;
};

class TextDocument: public Document{
    private:
    string text;
    public:
 
    TextDocument(string text){
        this->text = text;
    }
    string render() override{
        cout <<" The text Doucment -->"<< text <<" is viewed" << endl;
        return text;
    }

};

class ImageDocument: public Document{
    private:
    string imagePath;
    public:
    ImageDocument(string imagePath){
        this->imagePath = imagePath;
    }
    string render() override{
        cout <<" The Image Doucment -->" << imagePath <<" is viewed" << endl;
        return imagePath;
    }
};


class DocumentList{
    private:
    vector<Document*> documents;
    public:
    void addDocument(Document* document){
        documents.push_back(document);
    }

    string render(){
        string result;
        for(auto doc: documents){
            result += doc->render();
        }
        return result;
    }
};


class Persistence{
    public:
    virtual void save(string data)=0;
};

class SaveToDisk: public Persistence{
    public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

class SaveToMongoDb: public Persistence{
    public:
    void save(string d) override{
        cout << "Saving to MongoDb" << endl;
    }
};

class SaveToMySql: public Persistence{
    public:
    void save(string d) override{
        cout << "Saving to MySql" << endl;
    }
};

class DocumentEditor{
    public:
    DocumentList* dlist;
    Persistence* dbPersistence;
    string renderdDocument;
    
    DocumentEditor(DocumentList* doc , Persistence* dbPersistence){
        this->dlist = doc;
        this->dbPersistence = dbPersistence;
    }

    void addText(string text){
        dlist->addDocument(new TextDocument(text));
    }
    
    void addImage(string imagePath){
        dlist->addDocument(new ImageDocument(imagePath));
    }

    string renderDocument(){
        if(renderdDocument.empty()){
            renderdDocument = dlist->render();
            dbPersistence->save(renderdDocument);
        }
        return renderdDocument;

    }

    void saveDocumnet(){
        dbPersistence->save(renderDocument());
    }
};
int main (){
    DocumentList* dlist = new DocumentList();
    Persistence* dbPersistence = new SaveToDisk();
    DocumentEditor* editor = new DocumentEditor(dlist, dbPersistence);
    editor->addText("Hello world");
    editor->addImage("image.jpg");
    editor->renderDocument();
    editor->saveDocumnet();
    return 0;
}
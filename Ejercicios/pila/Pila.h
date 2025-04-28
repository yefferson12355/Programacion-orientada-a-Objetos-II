class Pila{
    private:
        Nodo* cima;

    public:

    Pila(){
        cima = NULL;
    }

    void Push(int v){
        Nodo *n = new Nodo(v);
        /*
        if(cima == NULL){
            cima = n;
        }else{
            n->unirCon(cima);
            cima = n;
        }
        */
        n->unirCon(cima);
        cima = n;
    }
    void Pop(){
        if(cima != NULL){
            Nodo *temp = cima;
            cima = temp->retSig();
            delete temp;
        }
    }
    void mostrarDatos(){
        Nodo *temp = cima;
        while(temp != NULL){
            cout<<temp->retDato()<<endl;
            temp = temp->retSig();
        }
    }
    int Size(){
        Nodo *temp = cima;
        int i=0;
        while(temp != NULL){
            i++;
            temp = temp->retSig();
        }
        return i;
    }
};

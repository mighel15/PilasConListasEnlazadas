#include <iostream>
using namespace std;

class Nodo {
    //Atributos
    int dato; //char, float, string, objeto
    Nodo* enlace;//puntero..
public:
    //Constructor - inicializar los atributos
    Nodo(int dato)
    {
        this->dato = dato;
        enlace = NULL;//por que no apuntamos a ningun nodo
    }
    //getter and setter
    int getDato()
    {
        return dato;
    }
    void setDato(int dato)
    {
        this->dato = dato;
    }
    Nodo* getEnlace()
    {
        return this->enlace;
    }
    void setEnlace(Nodo* enlace)
    {
        this->enlace = enlace;
    }
    void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Dato: " << dato << endl;
        cout << "|-------------------" << endl;
        cout << "|Enlace: " << enlace << endl;
        cout << "\\------------------/" << endl;
    }
};

class Lista {
    Nodo* inicio;
public:

    Lista()
    {
        this->inicio = NULL;
    }
    Nodo* getInicio()
    {
        return this->inicio;
    }
    void InsertarAlFinal(int dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            while (recorrido->getEnlace() != NULL)
            {
                recorrido = recorrido->getEnlace();
            }
            recorrido->setEnlace(temp);
        }
    }
    void InsertarAlInicio(int dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            this->inicio = temp;
            this->inicio->setEnlace(recorrido);
        }
    }
    void Imprimir()
    {
        int i = 1;
        Nodo* recorrido = inicio;
        cout << "Lista enlazada****************************" << endl;
        while (recorrido != NULL)
        {
            cout << "---> Nodo " << i++ << endl;
            recorrido->imprimir();
            recorrido = recorrido->getEnlace();
        }
        cout << "****************************" << endl << endl;
    }
    void ImprimirEnLinea()
    {
        Nodo* recorrido = inicio;
        cout << "Lista enlazada****************************" << endl;
        while (recorrido != NULL)
        {
            cout << recorrido->getDato() << "\t";
            recorrido = recorrido->getEnlace();
        }
        cout << "****************************" << endl << endl;
    }
    //Implementar la busqueda de un elemento en la lista enlazada
    //Si la encuentra tiene que imprimir la dirección de memoría
    //donde esta este elemento.
    bool Buscar(int datoBuscado)
    {
        bool encontrado = false;
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            if (recorrido->getDato() == datoBuscado)
            {
                encontrado = true;
                break;
            }
            else
            {
                recorrido = recorrido->getEnlace();
            }
        }
        return encontrado;

    }
    //------------------------------------
    //Implementar la eliminación de un nodo final
    int EliminarElementoFinal()
    {
        if (EstaVacia())
        {
            return NULL;
        }
        else
        {
            int datoEliminar = 0;
            if (inicio->getEnlace() == NULL)//unico nodo
            {
                datoEliminar = inicio->getDato();
                inicio = NULL;
            }
            else
            {
                Nodo* recorrido = inicio;
                while (recorrido->getEnlace() != NULL)
                {
                    //cout<<recorrido->getDato()<<"\t";
                    if (recorrido->getEnlace()->getEnlace() != NULL)
                        recorrido = recorrido->getEnlace();
                    else
                        break;
                }
                cout << endl;
                //recorrido->imprimir();
                datoEliminar = recorrido->getEnlace()->getDato();
                recorrido->setEnlace(NULL);

                //recorrido->imprimir();
            }
            return datoEliminar;

        }

    }
    void EliminarElementoEnPosicion(int posicion)
    {
        int contador = 0;
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (posicion == 0)
            {
                EliminarElementoInicio();
            }
            else
            {
                Nodo* recorrido = inicio;

                while (recorrido->getEnlace() != NULL)
                {
                    if (contador == posicion - 1)
                    {
                        recorrido->setEnlace(recorrido->getEnlace()->getEnlace());
                        break;
                    }
                    else
                    {
                        contador++;
                        recorrido = recorrido->getEnlace();
                    }

                }
            }


        }
    }

    void EliminarElementoInicio()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            inicio = inicio->getEnlace();
        }
    }
    void Vaciar()
    {
        inicio = NULL;
    }
    bool EstaVacia()
    {
        if (inicio == NULL)
            return true;
        else
            return false;
    }
    //Implementar la eliminación de un nodo inicio


    void InsertarDesendentemente(int dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            if (recorrido->getDato() < dato)
            {
                temp->setEnlace(this->inicio);
                this->inicio = temp;
            }
            else
            {
                while (recorrido->getEnlace() != NULL && recorrido->getEnlace()->getDato() > dato)
                {
                    recorrido = recorrido->getEnlace();
                }
                if (recorrido->getEnlace() == NULL)//insertarmos al final
                    recorrido->setEnlace(temp);
                else//inserta en el intermedio de dos nodos
                {
                    temp->setEnlace(recorrido->getEnlace());
                    recorrido->setEnlace(temp);
                }
            }

        }
    }
};

class Pila
{
    //atributos

    Lista elementos;

public:
    //constructor
    Pila()
    {
        elementos = Lista();
        indice = 0;
    }
    //Pila vacia
    bool PilaVacia()
    {
        if (elementos.getInicio() == NULL)//esta vacio???
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //Insertar elemento
    void Insertar(int elemento)//Push
    {
        elementos.InsertarAlFinal(elemento);//insertando al final de la lista
    }
    /// Quitar elemento
    int Quitar() // Pop
    {
        if (PilaVacia())
        {
            cout << "No hay en elementos en la pila" << endl;
            return NULL;
        }
        else
        {
            return elementos.EliminarElementoFinal();
        }
    }
    //Imprimir
    void Imprimir()
    {
        elementos.ImprimirEnLinea();
    }
};

void Menu()
{
    cout << "1) Insertar elemento " << endl;
    cout << "2) Quitar elemento " << endl;
    cout << "3) Imprimir pila " << endl;
    cout << "0) Salir " << endl;
}

int main()
{
    int opcion = 0;
    int elemento = 0;
    Pila pila = Pila();
    do
    {
        Menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese el elemento" << endl;
            cin >> elemento;
            pila.Insertar(elemento);
            break;
        case 2:
            cout << "El elemento quitado es: " << pila.Quitar() << endl;
            break;
        case 3:
            pila.Imprimir();
            break;

        default:
            cout << "opción no valida" << endl;
            break;
        }
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    } while (opcion != 0);

}

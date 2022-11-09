#include <iostream>

using namespace std;


int cont_tam = 0;
struct agenda //Tipo de dado definido pelo programador
{
    string nome;
    string telefone;
    agenda * prox;
    agenda * ant;
};

void inicio(agenda *&head) //Inicializando a lista
{
    head = NULL;
}
int tamanho (agenda *head) // Pegando o tamnaho da lista
{
    agenda *aux = head;
    while(aux != NULL)
    {
        cont_tam ++;
        aux = aux->prox;
    }
    return cont_tam;

}
void inserir_inicio(agenda *&head, string nome, string telefone) //Inserindo elementos no inicio da lista, quando for chamada no main
{
    agenda * novo = new agenda;
    novo->nome = nome;
    novo->telefone = telefone;
    novo->ant = NULL;
    novo->prox = NULL;

    if(head == NULL)
    {
        head = novo;
    }
    else
    {
        novo->prox = head;
        head->ant = novo;
        head = novo;

    }
}
void inserir_fim(agenda *&head, string nome, string telefone)//Inserir elementos no fim da lista, toda que for chamada no main
{
    agenda *novo = new agenda;
    novo->nome = nome;
    novo->telefone = telefone;
    novo->ant = NULL;
    novo->prox = NULL;

    if(head == NULL)
    {
        head = novo;
    }
    else
    {
        agenda *aux = head;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }

}
void inserir_pos (agenda *&head, string nome, string telefone, int pos) //Inserir elementos em uma posicao da lista, toda vez que for chamada no main
{
    agenda *novo = new agenda;
    novo->nome = nome;
    novo->telefone = telefone;
    novo->ant = NULL;
    novo->prox = NULL;

    if(head == NULL && pos == 0)
    {
        head = novo;

    }
    else if(pos == 0)
    {
        head->ant = novo;
        novo->prox = head;
        head = novo;

    }

    else
    {
        int cont = 1;
        agenda *perc = head->prox;
        while (cont != pos)
        {
            cont ++;
            perc = perc->prox;
        }
        perc->ant->prox = novo;
        novo->ant = perc->ant;
        novo->prox = perc;
        perc->ant = novo;
    }
}
void delet_ini(agenda *&head) //Deleta o primeiro elemento da lista, quando for chamada no main
{
    if(head == NULL)
    {
        cout<<"Lista NULA";

    }
    else if(head->prox == NULL)
    {
        delete head;
        head = NULL;
        cout<<"2 IF AQUI";
    }
    else
    {
        head = head->prox;
        delete head->ant;
        head->ant = NULL;
        cout<<"ELSE AQUI";
        printf("\n");
    }
}
void delet_fim(agenda *&head) //Deleta elemento no fim da lista, quando for chamada no main
{
    agenda *aux = head;

    if(head == NULL)
    {
        cout<<"Não foi possivel excluir contato\n";
    }
    else if(head->prox == NULL)
    {
        delete head;
        head = NULL;
        cout<<"Lista vazia";
    }
    else
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
    aux->ant->prox = NULL;
    delete aux;
}
void remover_pos(agenda *&head, int pos) //Remove elementos de uma posicao da lista, quando for chamada no main
{

    if(head->prox == NULL)
    {
        delete head;
        head = NULL;
        cout<<"Contato deletado com sucesso! 1 if";
    }
    else if (pos == 0)
    {
        head = head->prox;
        delete head->ant;
        head->ant = NULL;
        cout<<"Contato deletado com sucesso! 2 if";
    }
    else
    {
        int cont = 0;
        agenda *perc = head;
        while (cont != pos)
        {
            cont++;
            perc = perc->prox;
        }
        agenda *aux = perc->prox;
        aux->ant = perc -> ant;
        perc->ant->prox = aux;
        delete perc;
        cout<<"Contato deletado com sucesso! 3 else";
    }

}
void remover_repetidos(agenda *& head)  // deleta elementos repetidos da lista, quando for chamada no main
{
    agenda *perc = head;
    while(perc != NULL)
    {
        agenda *aux = perc->prox;
        while(aux != NULL)
        {
            if(perc->telefone == aux->telefone)
            {
                if(perc->ant != NULL)
                {
                    aux->ant->ant = perc->ant;
                    perc->ant->prox = aux->ant;
                    head = perc->ant;
                    delete perc;
                    break;
                }

                head = perc->prox;
                delete perc;
                head->ant = NULL;
                break;


            }
            aux = aux->prox;
        }
        perc = perc->prox;
    }
}

void buscar_contato(agenda *head, string nome)
{
    agenda *perc = head;
    bool valida = false;
    while(perc!=NULL)
    {
        if(nome == perc->nome)
        {
            valida = true;
            cout<<"Nome ["<<perc->nome <<"] \t "<< "Numero [" <<perc->telefone<<"] \n";
        }
        perc = perc->prox;
    }
    if(valida == false)
    {
        cout<<"Nome não encontrado";
    }
}
int imprimir_total(agenda *head)
{
    agenda *perc = head;
    int cont = 0;
    if(head == NULL)
    {
        return cont;
    }
    while(perc != NULL)
    {
        cont++;
        perc = perc->prox;
    }
    return cont;
}
void imprimir(agenda *head) //Imprime todos os elementos da lista, quando for chamada no main
{
    if(head == NULL)
    {
        cout<<"Não existe contatos";
    }
    else
    {
        agenda * aux = head;
        while(aux!=NULL)
        {
            cout<<"Nome ["<<aux->nome <<"] \t "<< "Numero [" <<aux->telefone<<"] \n";
            aux = aux->prox;
        }
    }
}

int main()
{

    agenda *head;
    inicio(head);
    int op = 0, retorno = -1;
    char letra;
    string nome, esco, telefone;



    do //1_repita tudo abaixo primeiro
    {
        do //2_repita tudo abaixo primeiro
        {
            cout<<"\nMEUNU DE OPCOES\n[1] Para inserir esse contato no inicio da tua lista\n[2] Para inserir esse contato no fim tua lista telefonica\n[3] Para inserir esse contato em uma posicao desejada\n[4] Para remover o primeiro contato inserido\n[5] Para remover o Utimo elemento\n[6] Para remover contato de uma posicao\n[7] Para buscar um contato\n[8] para listar os contatos\n[9] caso queira sair\nInforme o numero conforme o que queira fazer ";
            retorno = scanf("%d", &op); //O metodo scanf retorna bool para o tipo de valor requerido; neste caso: 1 para interiro, 0 para outro tipo diferente
            do //3_repita tudo abaixo primeiro
            {
                letra = getchar();
            }
            while(letra != '\n');
            //3_repita o de cima até que letra nao for diferente de ENTER
        }
        while(retorno == 0);
        //2_repita o de cima até que o retono nao seja mais igual a 0
        if(op == 1)
        {
            cout<<"Seu nome ";
            cin>>nome;
            cout<<"Seu telefone ";
            cin>>telefone;
            inserir_inicio(head, nome, telefone);
            cout<<"\nContato salvo com Sucesso";

        }
        else if(op == 2)
        {
            cout<<"Seu nome ";
            cin>>nome;
            cout<<"Seu telefone ";
            cin>>telefone;
            inserir_fim(head, nome, telefone);
            cout<<"\nContato salvo com Sucesso";

        }
        else if(op == 3)
        {
            cout<<"Seu nome ";
            cin>>nome;
            cout<<"Seu telefone ";
            cin>>telefone;
            int posi = -1;
            cout<<"Indforme a posicao da lista ";
            cin>>posi;
            while(posi > tamanho(head) || posi < 0)
            {
                cout<<"Posicao invalida, informe uma posicao diferente ";
                cin>>posi;
            }
            cout<<"\nContato salvo com Sucesso";
            inserir_pos(head, nome, telefone, posi);

        }

        else
        {

            if(op == 4)
            {
                delet_ini(head);
            }
            else if(op == 5)
            {
                delet_fim(head);
            }
            else if(op == 6)
            {
                int posi = 0;
                cout<<"Indforme a posicao da lista ";
                cin>>posi;
                while(posi > tamanho(head) || posi < 0)
                {
                    cout<<"Posicao invalida, informe uma posicao diferente ";
                    cin>>posi;
                }
                remover_pos(head, posi);
            }
            else if(op == 7)
            {
                string nome = " ";
                cout<<"Digite o nome do contato que queira procurar ";
                cin>>nome;
                buscar_contato(head, nome);
            }
            else if(op == 8)
            {
                imprimir(head);
            }
        }

    }

    while(op != 9);
    //1_repita o de cima até que digite 7
    printf("\n");
    remover_repetidos(head);
    imprimir(head);
    cout<<"Total de contatos: "<<imprimir_total(head)<<"\n";
}

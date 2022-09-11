// HashTable.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "main.h"

int main()
{
    std::cout << "Hello darkness my old friend!\n";

    srand(time(NULL));
    cout << endl;

    /*
     * Make test data
     * Note this does not guarantee a unique id
     */
    int testids[TESTDATASIZE];
    for (int i = 0; i < TESTDATASIZE; i++) {
        testids[i] = rand() % MAXID + 1;
    }

    /*
     * Show test data
     */
    cout << "Showing Test Data..." << endl;
    for (int i = 0; i < TESTDATASIZE; i++) {
        cout << testids[i] << " ";
    }
    cout << endl;
    cout << endl;

    Hashtable hashtable;

    /*
     * Insert all data to hash table
     */
    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < TESTDATASIZE; i++) {
        if (hashtable.insertEntry(testids[i])) {
            cout << "success. entry inserted." << endl;
            cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
        }
        else {
            cout << "failed. table is likely full." << endl;
        }
    }
    cout << endl;

    hashtable.printTable();
    cout << endl;

    /*
     * Retrieve all the test data from the table one at time
     */
    int temp;
    cout << "Retrieving Test Data on at a time..." << endl;
    for (int i = 0; i < TESTDATASIZE; i++) {
        temp = hashtable.getEntry(testids[i]);

        if (temp) {
            cout << "success: " << testids[i] << ": " << temp << endl;
        }
        else {
            cout << "failed: " << testids[i] << " is not in the table." << endl;
        }
    }
    cout << endl;

    /*
     * Remove the first, middle, and last of the
     * test data ids and one non-existent id
     */
    cout << "Deleting Test Data..." << endl;

    cout << "Trying: " << testids[0] << "..." << endl;
    if (hashtable.deleteEntry(testids[0])) {
        cout << "  Success: " << testids[0] << " removed" << endl;
    }
    else {
        cout << "  Failed " << testids[0] << " was not removed" << endl;
    }

    cout << "Trying: " << testids[(int)(TESTDATASIZE - 1) / 2] << "..." << endl;
    if (hashtable.deleteEntry(testids[(int)(TESTDATASIZE - 1) / 2])) {
        cout << "  Success: " << testids[(int)(TESTDATASIZE - 1) / 2] << " removed" << endl;
    }
    else {
        cout << "  Failed " << testids[(int)(TESTDATASIZE - 1) / 2] << " was not removed" << endl;
    }

    cout << "Trying: " << testids[TESTDATASIZE - 1] << "..." << endl;
    if (hashtable.deleteEntry(testids[TESTDATASIZE - 1])) {
        cout << "  Success: " << testids[TESTDATASIZE - 1] << " removed" << endl;
    }
    else {
        cout << "  Failed " << testids[TESTDATASIZE - 1] << " was not removed" << endl;
    }

    cout << "Trying: " << MAXID + 1 << "..." << endl;
    if (hashtable.deleteEntry(MAXID + 1)) {
        cout << "  Success: " << MAXID + 1 << " removed" << endl;
    }
    else {
        cout << "  Failed " << MAXID + 1 << " was not removed" << endl;
    }
    cout << endl;

    hashtable.printTable();
    cout << endl;

    cout << endl;
    return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln

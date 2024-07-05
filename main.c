#include <stdio.h>
#include <locale.h>

#define TAMANHO_LISTA_CONTATOS 50

struct contato{
        char nome[30];
        char email[30];
        long telefone;
    };

void imprimirListaContatos(struct contato listaContatos[TAMANHO_LISTA_CONTATOS], int quantidadeContatos){
    setlocale(LC_ALL, "Portuguese");
    if(quantidadeContatos > 0){
        printf("Lista de contatos cadastrados: \n\n");
        for (int i = 0; i < quantidadeContatos; i++){
            printf("\tContato [%d]: Nome: %s, Email: %s, Telefone: %ld \n", i + 1, listaContatos[i].nome, listaContatos[i].email, listaContatos[i].telefone);
        }
        printf("\nFim da lista\n");
    }else {
        printf("\nNenhum contato cadastrado\n");
    }
}

int cadastrarContato(struct contato listaContatos[TAMANHO_LISTA_CONTATOS], int quantidadeContatos){
    printf("Cadastrando novo contato.... \n");
    printf("Nome: \n");
    scanf("%s", listaContatos[quantidadeContatos].nome);
    printf("Email: \n");
    scanf("%s", listaContatos[quantidadeContatos].email);
    printf("Telefone: \n");
    scanf("%ld", &listaContatos[quantidadeContatos].telefone);
    quantidadeContatos++;
    return quantidadeContatos;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int resposta;
    int contatosCadastrados = 0;
    struct contato contatos[TAMANHO_LISTA_CONTATOS];

    while(1){
        printf("\n|1| Cadastrar novo contato \n|2| Listar todos os contatos \n|0| Sair do Programa\n");
        printf("\nDigite um numero para uma acao: ");
        scanf("%d", &resposta);

        if(resposta == 0){
            printf("Saindo do programa...");
            break;
        }

        switch (resposta)
        {
        case 1:
            contatosCadastrados = cadastrarContato(contatos, contatosCadastrados);
            break;
        case 2:
            imprimirListaContatos(contatos, contatosCadastrados);
            break;
        default:
            break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100

void openMenu();
void cadastrarFuncionario();
void planejamentosTurnos();
void trocaTurnos();
void printTurnos();

struct Turno
{
  int dia[100];
  int turno[100];
};
typedef struct funcionario
{
  char nome[50];
  char codigo[10];
  char cargo[50];
  struct Turno horario;
} Funcionario;

int main()
{
  setlocale(LC_ALL, "");
  openMenu();
}

void openMenu()
{
  int n;
  printf("---------MENU---------\n");
  printf("1 - Cadastrar funcionario\n");
  printf("2 - Planejamentos turnos\n");
  printf("3 - Troca de turnos\n");
  printf("4 - Visualizar turnos\n");
  printf("5 - Sair\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &n);

  switch (n)
  {
  case 1:
    cadastrarFuncionario();
    break;
  case 2:
    planejamentosTurnos();
    break;
  case 3:
    trocaTurnos();
    break;
  case 4:
    printTurnos();
    break;
  case 5:
    exit(0);
    break;
  default:
    printf("Opcao invalida!\n");
    return openMenu(n);
  }
}

void cadastrarFuncionario()
{

  int i, numFuncionarios = 0, j;
  printf("Digite o numero de funcionarios: ");
  scanf("%d", &numFuncionarios);

  Funcionario *funcionarios = malloc(numFuncionarios * sizeof(Funcionario));

  int id[numFuncionarios];
  for (i = 0; i < numFuncionarios; i++)
  {
    printf("Digite o nome do funcionario: ");
    fflush(stdin);
    scanf("%s", funcionarios[i].nome);
    printf("Digite o cargo do funcionario: ");
    fflush(stdin);
    scanf("%s", funcionarios[i].cargo);
    printf("Digite o codigo do funcionario: ");
    fflush(stdin);
    scanf("%s", funcionarios[i].codigo);
    id[i] = i + 1;

    for (j = 0; j < i; j++)
    {
      if (id[j] == id[i])
      {
        printf("Código já cadastrado. Por favor, digite outro código.\n");
        i--;
        break;
      }
    }
    if (j < i)
    {
      continue;
    }
  }
  
  planejamentosTurnos(numFuncionarios, funcionarios);
}
void planejamentosTurnos(int numFuncionarios, Funcionario *funcionarios)
{
  int i;
  for (i = 0; i < numFuncionarios; i++)
  {
    reset:; // label para retornar ao inicio do for usamos o goto para nos ajudar a sair do if
    printf("Digite o dia do funcionario %s: ", funcionarios[i].nome);
    scanf("%d", &funcionarios[i].horario.dia[i]);
    if(funcionarios[i].horario.dia[i] < 1 || funcionarios[i].horario.dia[i] > 30)
    {
      printf("erro, o dia tem que ser entre 1 e 30");
      goto reset;
    }
    printf("Digite o turno do funcionario %s: ( 1=Diurno, 2=Noturno )", funcionarios[i].nome);
    scanf("%d", &funcionarios[i].horario.turno[i]);

    if(funcionarios[i].horario.turno[i] == 2){
      printf("O funcionario so podera trabalhar novamente no dia %d ", funcionarios[i].horario.dia[i] + 2);
      printf("e horario Noturno\n");
    }
    
    if (funcionarios[i].horario.turno[i] == 1)
    {
      printf("O funcionario so podera trabalhar novamente no dia %d ", funcionarios[i].horario.dia[i] + 2);
      printf("e horario Diurno\n");
    }
    
  }
  trocaTurnos(numFuncionarios, funcionarios);
}
// Troca de plantões
void trocaTurnos(int numFuncionarios, Funcionario *funcionarios)
{
  int tempdia, tempturno; // variaveis temporarias para salvarem os dias e turnos incertos ate serem comparados com os ja cadastrados
  int i;
 
  for (i = 0; i < numFuncionarios; i++)
  {
    restart:; // label para retornar ao inicio do for usamos o goto para nos ajudar a sair do if
    printf("\nDigite o dia que o funcionario %s deseja trocar o turno:", funcionarios[i].nome);
    scanf("%d", &tempdia);
    if (funcionarios[i].horario.dia[i] + 1 == tempdia || funcionarios[i].horario.dia[i] == tempdia)
    {
      printf("erro, o funcionario tem que ter um descanso de 36 horas");
      goto restart;
    }
    if (funcionarios[i].horario.dia[i] + 2 == tempdia)
    {
      printf("Em qual turno o funcionario %s deseja trabalhar: ( 1=Diurno, 2=Noturno )", funcionarios[i].nome);
      scanf("%d", &tempturno);
      if (funcionarios[i].horario.turno[i] == tempturno)
      {
        printf("erro, o funcionario tem que ter um descanso de 36 horas");
        goto restart;
      }
      else
      {
        funcionarios[i].horario.dia[i] = tempdia;
        funcionarios[i].horario.turno[i] = tempturno;
        printf("Os turnos foram trocados!!!\n");
      }
    }

    if (funcionarios[i].horario.dia[i] + 2 < tempdia || funcionarios[i].horario.dia[i] > tempdia)
    {
      printf("Em qual turno o funcionario %s deseja trabalhar: ( 1=Diurno, 2=Noturno )", funcionarios[i].nome);
      scanf("%d", &tempturno);
      funcionarios[i].horario.dia[i] = tempdia;
      funcionarios[i].horario.turno[i] = tempturno;
      printf("Os turnos foram trocados!!!\n");
    }
  }

  printTurnos(funcionarios, numFuncionarios);
}
void printTurnos(Funcionario *funcionarios, int numFuncionarios)
{
  int i;
  for (i = 0; i < numFuncionarios; i++)
  {
    printf("\nNome: %s\n", funcionarios[i].nome);
    printf("Cargo: %s\n", funcionarios[i].cargo);
    printf("Codigo: %s\n", funcionarios[i].codigo);
    printf("Dia: %d", funcionarios[i].horario.dia[i]);
    if(funcionarios[i].horario.turno[i] == 1){
      printf(" Turno: Diurno");
    }else if(funcionarios[i].horario.turno[i] == 2){
      printf(" Turno: Noturno");
    }
    printf("\n");
  }
}

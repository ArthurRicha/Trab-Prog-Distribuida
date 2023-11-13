#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
  // Inicialização
  MPI_Init(&argc, &argv);

  // Leitura de tamanho e rank
  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Impressão
  std::cout << "Hello world, from process #" << rank << std::endl;
  
  // Finalização
  MPI_Finalize();

  return 0;
}

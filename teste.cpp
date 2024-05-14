extern "C" int run_prografo(char* executionType, char* filePath);

int main() {
  char executionType[] = "-d";
  char filePath[] = "/home/joaovitorffeijo/Desenvolvimento/polynomial_tree/examples/ex4.col";

  int result = run_prografo(executionType, filePath);

  return 0;
}
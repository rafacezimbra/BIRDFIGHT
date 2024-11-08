/* USAR SO SE NECESSARIO

void aplicarPoison(Birdmon *birdmon) {
    // Verifica se o Birdmon está envenenado
    if (birdmon->envenenado) {
        // Define o dano de veneno (10% do HP máximo)
        int danoPoison = birdmon->hpMax * 0.1; 

        // Aplica o dano de veneno
        birdmon->hpAtual -= danoPoison;

        // Garante que o HP não fique abaixo de zero
        if (birdmon->hpAtual < 0) {
            birdmon->hpAtual = 0;
        }

        void envenenarBirdmon(Birdmon *birdmon, int duracao) {
    birdmon->envenenado = 1;
    birdmon->duracaoPoison = duracao;
        }

        // Imprime o resultado do efeito de veneno
        printf("%s sofreu %d de dano por veneno! HP atual: %d\n", birdmon->nome, danoPoison, birdmon->hpAtual);

        // Reduz a duração do veneno
        birdmon->duracaoPoison--;

        // Se a duração do veneno acabou, remove o efeito
        if (birdmon->duracaoPoison <= 0) {
            birdmon->envenenado = 0;
            printf("%s não está mais envenenado.\n", birdmon->nome);
        }
    }
}
*/
import os
import shutil

def duplicar_hpp_para_cpp_recursivo(pasta_includes='includes', pasta_src='src'):
    """
    Percorre recursivamente a pasta 'includes', encontra todos os arquivos .hpp
    e os copia para a estrutura de pastas correspondente em 'src' como arquivos .cpp.
    """
    # Verifica se a pasta de origem principal existe
    if not os.path.isdir(pasta_includes):
        print(f"Erro: A pasta de origem '{pasta_includes}' não foi encontrada.")
        return

    # Garante que a pasta de destino principal exista
    if not os.path.exists(pasta_src):
        os.makedirs(pasta_src)
        print(f"Pasta de destino principal '{pasta_src}' criada.")

    print(f"Iniciando a varredura recursiva em '{pasta_includes}'...")
    print("-" * 30)

    # os.walk() percorre a árvore de diretórios de cima para baixo
    for dirpath, dirnames, filenames in os.walk(pasta_includes):
        # Para cada pasta encontrada, calcula o caminho da pasta de destino correspondente
        # Ex: se dirpath é 'includes/componentes', dest_dir_path será 'src/componentes'
        dest_dir_path = dirpath.replace(pasta_includes, pasta_src, 1)

        # Cria a pasta de destino se ela não existir
        if not os.path.exists(dest_dir_path):
            os.makedirs(dest_dir_path)
            print(f"Diretório criado: '{dest_dir_path}'")

        # Agora, processa os arquivos dentro da pasta atual (dirpath)
        for filename in filenames:
            # Verifica se o arquivo é um .hpp
            if filename.endswith('.hpp'):
                # Monta o caminho completo do arquivo de origem
                caminho_arquivo_origem = os.path.join(dirpath, filename)

                # Monta o caminho completo do arquivo de destino
                nome_base, _ = os.path.splitext(filename)
                nome_arquivo_cpp = f"{nome_base}.cpp"
                caminho_arquivo_destino = os.path.join(dest_dir_path, nome_arquivo_cpp)

                try:
                    # Copia o arquivo
                    shutil.copy2(caminho_arquivo_origem, caminho_arquivo_destino)
                    print(f"  - Copiado: '{caminho_arquivo_origem}' -> '{caminho_arquivo_destino}'")
                except Exception as e:
                    print(f"  - Erro ao copiar '{filename}': {e}")

    print("-" * 30)
    print("Processo concluído!")


if __name__ == '__main__':
    pasta_de_includes = 'includes'
    pasta_de_src = 'src'

    duplicar_hpp_para_cpp_recursivo(pasta_de_includes, pasta_de_src)
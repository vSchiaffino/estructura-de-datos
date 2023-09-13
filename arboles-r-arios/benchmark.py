import subprocess
import time
import json

def ejecutar_comando(comando):
    tiempo_inicio = time.time()
    subprocess.call(comando, shell=True)
    tiempo_fin = time.time()
    tiempo_total = tiempo_fin - tiempo_inicio
    return tiempo_total * 1000

def hacer_benchmark(comando_archivo, comando_memoria, nombre_archivo):
    benchmarks = []
    NIVELES_MAXIMOS = 10
    for niveles in range(NIVELES_MAXIMOS):
        ejecutar_comando(f"./crear_arbol {niveles}")        
        tiempo_archivo = ejecutar_comando(comando_archivo)
        tiempo_memoria = ejecutar_comando(comando_memoria)
        benchmarks.append({
            "nivel": niveles,
            "memoria": tiempo_memoria,
            "archivo": tiempo_archivo
        })
    print(benchmarks)
    with open(nombre_archivo, "w") as f:
        f.write(json.dumps(benchmarks, indent=2))

def main():
    hacer_benchmark("./pre_orden_archivo", "./pre_orden_memoria", "benchmark_preorden.json")
    hacer_benchmark("./niveles_archivo", "./niveles_memoria", "benchmark_niveles.json")
        

if(__name__ == "__main__"):
    main()
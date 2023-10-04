import subprocess
import time
import json

def guardar_salida_de(comando):
    proceso = subprocess.Popen(comando, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    salida_stdout, salida_stderr = proceso.communicate()

    return salida_stdout.decode('utf-8')

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
    with open(nombre_archivo, "w") as f:
        f.write(json.dumps(benchmarks, indent=2))

def hacer_benchmark_buscar():
    benchmarks = []
    for nivel in range(3, 25):
        valor_buscado = guardar_salida_de(f"./crear_arbol_ordenado {nivel}")
        tiempo_archivo = ejecutar_comando(f"./buscar_archivo {valor_buscado}")
        tiempo_memoria = ejecutar_comando(f"./buscar_memoria {valor_buscado}")
        benchmarks.append({
            "nivel": nivel,
            "memoria": tiempo_memoria,
            "archivo": tiempo_archivo
        })
    with open("benchmark_buscar.json", "w") as f:
        f.write(json.dumps(benchmarks, indent=2))
    

def main():
    hacer_benchmark("./pre_orden_archivo", "./pre_orden_memoria", "benchmark_preorden.json")
    hacer_benchmark("./niveles_archivo", "./niveles_memoria", "benchmark_niveles.json")
    # hacer_benchmark_buscar()
        

if(__name__ == "__main__"):
    main()
import subprocess
import shlex


results_file = '../results/raw_output'
bin_runner = '../bin/runner '


def main():
    number_of_experiments = [50] # just 50 for now. If I don't get interesting data, i'll increase
    number_of_objects = range(1000, 100000, 1000)
    distributions = [0,1]
    algorithms = [0,1]
    with open(results_file, 'a') as f:
        for exp in number_of_experiments:
            for objs in number_of_objects:
                for d in distributions:
                    for a in algorithms:
                        args = [bin_runner + str(exp) + ' ' + str(objs) + ' ' + str(d) + ' ' + str(a)]
                        c = subprocess.run(args, stdout=f, shell=True)

    return 0

if __name__ == "__main__":
    main()
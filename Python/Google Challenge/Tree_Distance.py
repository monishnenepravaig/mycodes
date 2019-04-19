import re
import string

class tree_graph:

    def __init__(self,number_value=None):
        self.value=number_value
        self.edges=[]

    def add_edges(self,node=None):
        self.edges.append(node);

def calculate_minimum_distance():
    return 0

def write_to_file(file_name,data):
    file = open(file_name, "a")
    file.write(str(data))
    file.close
        
if __name__ == "__main__":
    fp = open("task2-sample-input.txt","r")
    total_cases=int(fp.readline())
    for i in range(1,total_cases+1):
        dummy=fp.readline()
        total_nodes=int(fp.readline())
        nodes=[]
        for k in range(1,total_nodes+1):
            node=tree_graph(k)
            nodes.append(node)
        for edge in range(total_nodes-1):
            line_in=fp.readline()
            n=[]
            for z in line_in.split():
                if z.isdigit():
                    n.append(z)
            nodes[int(n[0])-1].add_edges(nodes[int(n[1])-1])
            nodes[int(n[1])-1].add_edges(nodes[int(n[0])-1])
        x=calculate_minimum_distance()
        op="Case #"+str(i)+": "+str(x)+"\n"
        print(op)
        write_to_file("task2-output.txt", op)
    fp.close

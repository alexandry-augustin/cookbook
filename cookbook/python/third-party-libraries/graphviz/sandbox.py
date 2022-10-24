import graphviz

if __name__ == '__main__':

    dot = graphviz.Digraph(comment='The Round Table')

    dot.node(name='A', label='Label A')
    dot.node(name='B', label='Label B')
    dot.node(name='C', label='Label C')

    #dot.edges(['AB', 'AC'])
    dot.edge('A', 'B', constraint='true')
    dot.edge('A', 'C', constraint='true')
    dot.edge('B', 'C', constraint='false')

    print(dot.source)
    dot.render('out/out.gv').replace('\\', '/')

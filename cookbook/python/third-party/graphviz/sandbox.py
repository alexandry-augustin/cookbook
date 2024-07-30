import graphviz

def test_00():

    graph = graphviz.Digraph(comment='G', 
                            #  filename='temp_graph.gv'
                             )
    graph.node_attr['fontname'] = 'Courier New'
    graph.edge_attr['fontname'] = 'Courier New'
    graph.attr('node', {'fontname': 'Courier New'})
    graph.attr('edge', {'fontname': 'Courier New'})

    graph.node(name='A',
               label='Label A',
               xlabel='xlabel',
               shape = 'oval',
               color = 'mistyrose', 
               style = 'filled',
            #    _attributes={"style": "invis"} 
               # key1='value1',
               # key2='value2'
               )
    graph.node(name='B', label='Label B')
    graph.node(name='C', label='Label C')

    #graph.edges(['AB', 'AC'])
    graph.edge('A', 'B', 
               constraint='true', 
               label = 'AB',
               color = 'skyblue',
               style = 'dashed')
    graph.edge('A', 'C', constraint='true')
    graph.edge('B', 'C', constraint='false')

    return graph

def test_01():

    pass

if __name__ == '__main__':

    graph = test_00()

    # print(graph.source)
    graph.view()
    # graph.render('out/out.gv').replace('\\', '/')
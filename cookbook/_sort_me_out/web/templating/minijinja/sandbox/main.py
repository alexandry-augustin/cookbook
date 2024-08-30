from minijinja import Environment

if __name__ == '__main__': 

    with open('templates/base.html', 'r') as file:
        base = file.read()

    with open('templates/index.html', 'r') as file:
        template = file.read()

    env = Environment(
        templates={
            'base': base, 
            'template_name': template
        }
    )
    
    data = {
        'str': 'a string',
        'list': [ 'a', 'b', 'c' ],
    }

    result = env.render_template(
        'template_name', 
        var1="value 1", 
        data=data)
    
    print(result)


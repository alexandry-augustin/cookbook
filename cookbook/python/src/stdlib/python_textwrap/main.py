import textwrap

if __name__ == '__main__':

    sample_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."

    wrapped_text = textwrap.wrap(sample_text, width=50) 
    print('\n'.join(wrapped_text)) 

    # Similar to wrap(), but returns a single string with newline characters instead of a list of lines. 
    filled_text = textwrap.fill(sample_text, width=50) 
    print(filled_text)

    indented_text = textwrap.indent(sample_text, "\t") 
    print(indented_text)

    dedented_text = textwrap.dedent(indented_text) 
    print(dedented_text)

    shortened_text = textwrap.shorten(sample_text, width=30, placeholder="...")
    print(shortened_text)
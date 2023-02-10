// https://stackoverflow.com/questions/901115/how-can-i-get-query-string-values-in-javascript
function get_query_params(str) {
    const params = new Proxy(new URLSearchParams(str), {
        get: (search_params, prop) => search_params.get(prop),
    });

    return params
}

function build_query_string(params) {

    const param_obj = new URLSearchParams(params);
    return param_obj.toString();
}

window.onload = function() {

    let params = {
        name: "john",
        age: 18
    }
    const query_string = build_query_string(params);
    console.log(query_string);

    // window.location.search
    const params_ = get_query_params(query_string);
    console.log(params);

    let age = params_.age;
    console.log('age=', age);
}
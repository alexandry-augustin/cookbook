window.dataTable = function () {

  return {

    includeFields: [
      'name', 
      'email', 
      'job', 
      'country', 
      'year'
    ], // null to include all fields
    headers: null, 
    items: null,

    searchInput: '',
    searchFields: [
      'name', 
      'job'
    ],
    
    view: 5,

    pages: [],
    offset: 5,
    currentPage: 1,
    pagination: {
      total: data.length,
      lastPage: Math.ceil(data.length / 5),
      perPage: 5,
      currentPage: 1,
      from: 1,
      to: 1 * 5
    },

    sorted: {
      field: 'name',
      rule: 'asc'
    },

    initData() {

      // https://stackoverflow.com/questions/2802341/natural-sort-of-alphanumerical-strings-in-javascript
      // this.collator = new Intl.Collator(undefined, { numeric: true, sensitivity: 'base' });

      // Get headers
      let headers = data.map(e => Object.keys(e));
      headers = headers.flat();
      headers = headers.filter(x => this.includeFields.includes(x));
      this.headers = [...new Set(headers)];

      this.items = data.sort(this.compareOnKey(this.sorted.field, this.sorted.rule));

      this.showPages();
    },

    compareOnKey(key, rule) {

      return function(a, b) { 

        // FIXME localeCompare() fail if fieldA is of type 'numeric'
        const fieldA = String(a[key]);
        const fieldB = String(b[key]);
        
        if(rule === 'asc')
          return fieldA.localeCompare(fieldB, undefined, { numeric: true, sensitivity: 'base' });
        else
          return fieldB.localeCompare(fieldA, undefined, { numeric: true, sensitivity: 'base' });
      }
    },

    checkView(index) {
      return index > this.pagination.to || index < this.pagination.from ? false : true;
    },

    checkPage(item) {
      return item <= (this.currentPage + 5);
    },

    search(value) {

      if(value.length > 1) {

        const options = {
          shouldSort: true,
          keys: this.searchFields,
          threshold: 0
        }
        const fuse = new Fuse(data, options);
        this.items = fuse.search(value).map(elem => elem.item);
      } else
        this.items = data;

      // console.log(this.items.length);
      
      this.changePage(1);
      this.showPages();
    },

    sort(field, rule) {

      // console.log(`${field}, ${rule}`);
      this.items = this.items.sort(this.compareOnKey(field, rule));

      this.sorted.field = field;
      this.sorted.rule = rule;
    },

    toggleSort(field) {
      this.sort(field, this.sorted.rule == 'asc' ? 'desc' : 'asc');
    }, 

    changePage(page) {

      if(page >= 1 && page <= this.pagination.lastPage) {
        
        this.currentPage = page;
        const total = this.items.length;
        const lastPage = Math.ceil(total / this.view) || 1;
        const from = (page - 1) * this.view + 1;
        let to = page * this.view;
        if(page === lastPage)
          to = total;
        this.pagination.total = total;
        this.pagination.lastPage = lastPage;
        this.pagination.perPage = this.view;
        this.pagination.currentPage = page;
        this.pagination.from = from;
        this.pagination.to = to;
        this.showPages();
      }
    },

    showPages() {

      const pages = [];
      let from = this.pagination.currentPage - Math.ceil(this.offset / 2);
      if(from < 1)
        from = 1;
      let to = from + this.offset - 1;
      if(to > this.pagination.lastPage)
        to = this.pagination.lastPage;
      while (from <= to) {
        pages.push(from);
        from++;
      }
      this.pages = pages;
    },

    changeView() {
      this.changePage(1);
      this.showPages();
    },

    isEmpty() {
      return this.pagination.total ? false : true;
    }
  }
}
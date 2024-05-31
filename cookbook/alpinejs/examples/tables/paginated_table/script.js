document.addEventListener('alpine:init', () => {
    Alpine.data('catData', () => ({
      cats:null,
      sortCol:null,
      sortAsc:false,
      pageSize:4,
      curPage:1,
      async init() {
        let resp = await fetch('https://www.raymondcamden.com/.netlify/functions/get-cats');
        // Add an ID value
        let data = await resp.json();
        data.forEach((d,i) => d.id = i);
        this.cats = data;
      },
      nextPage() {
        if((this.curPage * this.pageSize) < this.cats.length) this.curPage++;
      },
      previousPage() {
        if(this.curPage > 1) this.curPage--;
      },
      sort(col) {
        if(this.sortCol === col) this.sortAsc = !this.sortAsc;
        this.sortCol = col;
        this.cats.sort((a, b) => {
          if(a[this.sortCol] < b[this.sortCol]) return this.sortAsc?1:-1;
          if(a[this.sortCol] > b[this.sortCol]) return this.sortAsc?-1:1;
          return 0;
        });
      },
      get pagedCats() {
        if(this.cats) {
          return this.cats.filter((row, index) => {
            let start = (this.curPage-1)*this.pageSize;
            let end = this.curPage*this.pageSize;
            if(index >= start && index < end) return true;
          })
        } else return [];
      }
    }))
  });
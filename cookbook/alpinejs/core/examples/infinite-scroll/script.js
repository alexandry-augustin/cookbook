// https://www.entreprehero.com/infinite-scroll-using-alpinejs/
function infiniteScroll() {
      return {
        triggerElement: null,
        page: 1,
        lastPage: null,
        itemsPerPage: 10,
        observer: null,
        isObserverPolyfilled: false,
        items: [],
        init(elementId) {
          const ctx = this
          this.triggerElement = document.querySelector(elementId ? elementId : '#infinite-scroll-trigger')

          // Check if browser can use IntersectionObserver which is waaaay more performant
          if (!('IntersectionObserver' in window) ||
              !('IntersectionObserverEntry' in window) ||
              !('isIntersecting' in window.IntersectionObserverEntry.prototype) ||
              !('intersectionRatio' in window.IntersectionObserverEntry.prototype))
          {
              // Loading polyfill since IntersectionObserver is not available
              this.isObserverPolyfilled = true

              // Storing function in window so we can wipe it when reached last page
              window.alpineInfiniteScroll = {
                scrollFunc() {
                  var position = ctx.triggerElement.getBoundingClientRect()

                	if(position.top < window.innerHeight && position.bottom >= 0) {
                    ctx.getItems()
                	}
                }
              }

              window.addEventListener('scroll', window.alpineInfiniteScroll.scrollFunc)
          } else {
            // We can access IntersectionObserver
            this.observer = new IntersectionObserver(function(entries) {
              if(entries[0].isIntersecting === true) {
                ctx.getItems()
              }
            }, { threshold: [0] })

            this.observer.observe(this.triggerElement)
          }

          this.getItems()
        },
        getItems() {
          // TODO: Do fetch here for the content and concat it to populated items
          // TODO: Set last page from API call - ceil it

          // SOF: Dummy Data
          this.lastPage = 5
          console.log('Simulating fetching items...')
          let dummyAdd = this.page === 1 ? 1 : 1 + (this.page - 1) * this.itemsPerPage
          this.items = this.items.concat(Array.from({length: this.itemsPerPage}, (_, i) => i + dummyAdd))
          // EOF: Dummy Data

          // Next page
          this.page++

          // We have shown the last page - clean up
          if(this.lastPage && this.page > this.lastPage) {
            if(this.isObserverPolyfilled) {
              window.removeEventListener('scroll', window.alpineInfiniteScroll.scrollFunc)
            } else {
              this.observer.unobserve(this.triggerElement)
            }

            this.triggerElement.parentNode.removeChild(this.triggerElement)
          }
        }
      }
    }
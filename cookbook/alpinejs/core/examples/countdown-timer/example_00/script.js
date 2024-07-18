function timer(expiry) {

  return {
    
    expiry: expiry,
    remaining: null,

    init() {
      this.setRemaining();
      // call setRemaining() every second
      setInterval(() => {
          this.setRemaining();
      }, 1000);
    },

    setRemaining() {
      const diff = this.expiry - new Date().getTime();
      if(diff >= 0)
        this.remaining =  parseInt(diff / 1000);
    },

    days() {
      return {
      	value:this.remaining / 86400,
        remaining:this.remaining % 86400
      };
    },

    hours() {
      return {
      	value:this.days().remaining / 3600,
        remaining:this.days().remaining % 3600
      };
    },

    minutes() {
    	return {
      	value:this.hours().remaining / 60,
        remaining:this.hours().remaining % 60
      };
    },

    seconds() {
    	return {
      	value:this.minutes().remaining,
      };
    },

    format(value) {
      return ("0" + parseInt(value)).slice(-2)
    },

    time() {
    	return {
      	days:this.format(this.days().value),
        hours:this.format(this.hours().value),
        minutes:this.format(this.minutes().value),
        seconds:this.format(this.seconds().value),
      }
    },
  }
}
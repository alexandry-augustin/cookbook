// Alpine 2.3.5
function pinHandler() {
  return { 
    length: 5,
    value: '',
    validation: /\d/g,
    updateValue() {
      this.value = Array.from({ length: this.length }, (empty, index) => {
        return this.$refs[index].value || ' '
      }).join('')
    },
    handleInput(pin) {
      const value = pin.value.match(this.validation)
      // if the input doesn't match our needs, don't do anything
      if (!value || !value.length) {
        pin.value = ''
        return
      }
      
      // TODO: We could check here if the value.length = length then check against a database
      
      pin.value = value
      this.updateValue()
      this.focusNextRef(pin.getAttribute('x-ref'))
    },
    handlePaste(event) {
      // TODO: this validation might not be what your app requires (this one is numbers only)
      const text = event.clipboardData.getData('Text').match(this.validation)
      if (!text || !text.length) return
      // Get the starting input
      const pastedFrom = parseInt(event.target.getAttribute('x-ref'), 10)
      // This filters only numbers, then slices based on how many inputs remain
      const remainingInputs = this.length - pastedFrom
      const value = text.slice(0, remainingInputs).join('')
      // Figure out what inputs we need to update
      const inputsToUpdate = Array.from(Array(remainingInputs), (empty, index) => {
        return index + pastedFrom
      }).splice(0, value.length)
      // Update the values
      inputsToUpdate.forEach((ref, i) => {
        this.$refs[ref].value = value[i]
      })
      // Focus the last input we updated
      this.focusNextRef(inputsToUpdate.pop())
      this.updateValue()
    },
    focusNextRef(current) {
      const next = parseInt(current, 10) + 1
      if (!this.$refs[next]) {
        // If next doesn't exist, focus the last. A real app might auto check the database or focus a button
        this.$refs[parseInt(this.length, 10) - 1].focus()
        this.$refs[parseInt(this.length, 10) - 1].select()
        return
      }
      this.$refs[next].focus()
      this.$refs[next].select()
    },
    focusPreviousRef(current) {
      const previous = parseInt(current, 10) - 1
      this.$refs[previous] && this.$refs[previous].focus()
      this.$refs[previous] && this.$refs[previous].select()
    },
  }
}
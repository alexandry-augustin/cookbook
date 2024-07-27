function otpForm() {
    return {
        
        length: 6,
        value: "",

        get inputs() {
            return this.$refs.otpInputContainer.querySelectorAll('.otpInput');
        },

        handleInput(e, index) {
            const inputValues = [...this.inputs].map(input => input.value);
            this.value = inputValues.join('');
            if (e.target.value) {
                const nextInput = this.inputs[index + 1];
                if (nextInput) {
                    nextInput.focus();
                    nextInput.select();
                }
            }
        },

        handlePaste(e) {
            const paste = e.clipboardData.getData('text').slice(0, this.length);
            paste.split('').forEach((char, i) => {
                if (this.inputs[i]) {
                    this.inputs[i].value = char;
                }
            });
            this.value = [...this.inputs].map(input => input.value).join('');
        },

        handleBackspace(e, index) {
            if (index > 0) {
                this.inputs[index - 1].focus();
                this.inputs[index - 1].select();
            }
        },
    };
}
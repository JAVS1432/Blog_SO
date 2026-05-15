const modeToggle = document.getElementById("modeToggle");
const root = document.body;

if (modeToggle) {
  modeToggle.addEventListener("click", () => {
    root.classList.toggle("light");
  });
}

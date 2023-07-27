import { useState } from "react";
import Monitor from "./components/Monitor";

function App() {
  const [isShow, setIsShow] = useState(false);

  return (
    <div className="w-screen h-screen flex flex-col justify-center items-center gap-10">
      {isShow === false ? (
        <button
          className="text-5xl font-semibold bg-blue-300 p-8 rounded-lg"
          onClick={() => setIsShow(true)}
        >
          Mulai Monitoring
        </button>
      ) : (
        <Monitor />
      )}
    </div>
  );
}

export default App;

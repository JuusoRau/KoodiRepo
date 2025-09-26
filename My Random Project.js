import * as THREE from 'three';

const scene = new THREE.scene();
const camera = new THREE.PerspectiveCamera(95, 
window.innerWidth / window.innerHeight, 0.1, 1000);

const renderer = new THREE.WebGLRenderer();
renderer.setsize(window.innerWidth, window.
innerHeight);
document.body.appendChild(renderer.domElement); 

const geometry = new THREE.BoxGeometry();
const material = new THREE.MeshBasicMaterial({
color: 0xff000 });
const sphere = new THREE.Mesh(geometry, material);
scene.add(sphere);

camera.position.z = 7;

function animate() {
  requestAnimationFrame(animate);

  sphere.rotation.x += 0.05;
  sphere.rotation.y += 0.15;

  renderer.render(scene, camera);
}

animate();
